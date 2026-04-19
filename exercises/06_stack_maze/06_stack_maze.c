#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

int visited[MAX_ROW][MAX_COL] = {0};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void)
{
	int stack_x[50];
    int stack_y[50];
    int stack_dir[50];

    int top = 0;
    int flag = 0;

    stack_x[top] = 0;
    stack_y[top] = 0;
    stack_dir[top] = 0;
    top++;

    visited[0][0] = 1;

    while (top > 0) {
        int x = stack_x[top - 1];
        int y = stack_y[top - 1];

        if (x == MAX_ROW - 1 && y == MAX_COL - 1) {
            flag = 1;
            break;
        }

        if (stack_dir[top - 1] >= 4) {
            visited[x][y] = 0;
            top--;
            continue;
        }

        int d = stack_dir[top - 1];
        stack_dir[top - 1]++;

        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || nx >= MAX_ROW || ny < 0 || ny >= MAX_COL) {
            continue;
        }

        if (maze[nx][ny] == 1 || visited[nx][ny]) {
            continue;
        }

        stack_x[top] = nx;
        stack_y[top] = ny;
        stack_dir[top] = 0;
        top++;

        visited[nx][ny] = 1;
    }

	// TODO: 在这里添加你的代码
	if(flag){
		printf("Path:\n");
		for(int i= 0; i<top; i++){
			printf("(%d,%d) ", stack_x[i], stack_y[i]);

			if (i != top - 1) {
                printf("->");
            }
		}
	}else{
		printf("No Path!");
	}
	
	return 0;
}