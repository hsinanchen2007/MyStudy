### 解题思路
执行用时 8 ms	
内存消耗 8.4 MB

1 把障碍物k 作为最多可经过多少个障碍
2 使用二位数组visit 作为能否经过的判断条件（-1 ：未经过  其他：路径从该点出发 还能再经过的障碍数）

    举例1：A路径到达该点时 还可以再经过3个障碍
    B路径到达该点时 还可以再经过1个障碍
    则认为B路径不如A路径，不能加入队列

    举例2：A路径到达该点时 还可以再经过3个障碍
    B路径到达该点时 还可以再经过3个障碍
    则认为B路径与A路径无差别，不必加入队列

    ps：3维数组也是这个意思
3 C语言使用数据实现队列 通过宏优化代码执行时间（缺点 数组较长）
    ps：如果使用循环队列的话 队列长度最大只需要 39*39*4
### 代码

```c
#define NEWQLEN 100000

typedef struct {
    int x;
    int y;
    int blk;
}DATA;

int dirt[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

#define EnQueue(q,data) (q[End++] = data)
#define DeQueue(q) (q[Begin++])
int shortestPath(int** grid, int gridSize, int* gridColSize, int k){

    int m = gridSize;
    int n = gridColSize[0];
    if((m == 1) && (n == 1)){
        return 0;
    }

    DATA q[NEWQLEN];
    int Begin = 0;
    int End = 0;
    int visit[m][n];
    memset(q, 0, sizeof(DATA)*NEWQLEN);
    memset(visit, -1, sizeof(int)*m*n);
    DATA tmp = {0,0,k};
    EnQueue(q, tmp);

    int cnt = 0;
    for (int step = 1; End - Begin >0; ++step) {
        cnt = End - Begin;
        for(int i=0; i<cnt; i++) {
            DATA dd = DeQueue(q);
            for(int j=0; j<4; j++) {
                int newX = dd.x + dirt[j][0];
                int newY = dd.y + dirt[j][1];

                if((newX == m-1) && (newY == n-1)) {
                    return step;
                }
                if((newX<0) || (newX>m-1) || (newY<0) || (newY>n-1)) {
                    continue;
                }

                if(dd.blk - grid[newX][newY] > visit[newX][newY]) {
                    tmp.x = newX;
                    tmp.y = newY;
                    tmp.blk = dd.blk-grid[newX][newY];
                    EnQueue(q, tmp);
                    visit[newX][newY] = dd.blk-grid[newX][newY];
                }
            }
        }
    }

    return -1;
}

```