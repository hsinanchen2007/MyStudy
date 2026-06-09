### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/fc4d57fc66a85658d9933d1e68b7c87e326c187e04af79f62f93481a9b9fabba-image.png)


### 代码

```c
#define MAX_NODE_NUM    201
int g_status[MAX_NODE_NUM][MAX_NODE_NUM][2];

int calcStatus(int **arry, int *len, int x, int y)
{
    int i;
    int flag = 0;
    int status = 0;

    if (0 == g_status[x][y][0]) { //老鼠的局
        for (i = 0; i < len[x]; i++) {
            if (1 == g_status[arry[x][i]][y][1]) {
                g_status[x][y][0] = 1;
                flag = 1;
                status = 1;
                break;
            }
            if (2 != g_status[arry[x][i]][y][1]) {
                status  = 1;
            }
        }
        if (0 == status) {  //下一步全是猫赢
            g_status[x][y][0] = 2;
            flag = 1;
        }
    }
    
    if (0 == g_status[x][y][1]) {   //猫的局
        status = 0;
        for (i = 0; i < len[y]; i++) {
            if (2 == g_status[x][arry[y][i]][0]) {
                g_status[x][y][1] = 2;
                flag = 1;
                status = 1;
                break;
            }
            if ((1 != g_status[x][arry[y][i]][0]) && (0 != arry[y][i])) {
                status = 1;
            }
        }
        if (0 == status) {  //下一步全是老鼠赢
            flag = 1;
            g_status[x][y][1] = 1;
        }
    }

    return flag;
}


int catMouseGame(int** graph, int graphSize, int* graphColSize)
{
    int i;
    int j;
    int flag = 1;

    memset(g_status, 0, sizeof(int) * MAX_NODE_NUM * MAX_NODE_NUM * 2);
    for (i = 0; i < MAX_NODE_NUM; i++) {
        g_status[i][i][0] = 2;
        g_status[i][i][1] = 2;
        g_status[0][i][0] = 1;
        g_status[0][i][1] = 1;
    }

    while (flag) {
        flag = 0;
        for (i = 1; i < graphSize; i++) {
            for (j = 1; j < graphSize; j++) {
                if (i == j) {
                    continue;
                }
                flag |= calcStatus(graph, graphColSize, i, j);
            }
        }
    }

    return g_status[1][2][0];
}
```