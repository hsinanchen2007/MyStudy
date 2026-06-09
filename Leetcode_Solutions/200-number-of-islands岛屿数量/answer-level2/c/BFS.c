### 解题思路
此处撰写解题思路

### 代码

```c
// BFS
#define MAX_LEN 100000
#define DIR 4
int dir[DIR+1] = {0,1, 0, -1, 0};
int **g_visited;
typedef struct {
    int x;
    int y;
}Node;
typedef struct {
    int tail;
    int top;
    Node node[MAX_LEN];
}Que;
void EnQue(Que *que, Node *node) {
    que->node[que->top] = *node;
    que->top++;
}
void DelQue(Que *que, Node *node) {
   *node = que->node[que->tail];
    que->tail++;
}
int  GetQue(Que *que) {
    return (que->top - que->tail);
}

void PrQue(Que *que) {
   int tail = que->tail;
   printf("\r\n que \r\n");
   while(tail != que->top) {
       printf("%3d,%3d     ",que->node[tail].x,que->node[tail++].y );
   }
}
Que g_que;
void BFS(char** grid, int row, int col, int x, int y) {
    Node delNode, enNode;
    int loop, i, j;

    enNode.x = x;
    enNode.y = y;
    EnQue(&g_que,&enNode);
    //PrQue(&g_que);
    while(GetQue(&g_que)) {
        DelQue(&g_que,&delNode);
        for(loop = 0; loop < DIR; loop++) {
            i = delNode.x + dir[loop];
            j = delNode.y + dir[loop + 1];
            if(i >= 0 && i <= row -1 && j >= 0 && j <= col - 1) {
                if(grid[i][j] == '1' && g_visited[i][j] == 0) {
                    enNode.x = i;
                    enNode.y = j;
                    EnQue(&g_que,&enNode);
                    g_visited[i][j] = 1;
                }
            }
        }
    }
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
    int rst = 0;
    int i, j;

    memset(&g_que, 0 ,sizeof(g_que));
    g_visited = calloc(gridSize, sizeof(int*));
    for(i = 0; i< gridSize; i++){
        g_visited[i] = calloc(gridColSize[0],sizeof(int));
    }

    for(i = 0; i < gridSize; i++) {
        for(j = 0; j< gridColSize[0]; j++) {
            if(grid[i][j] == '1' && g_visited[i][j] == 0) {
                BFS(grid, gridSize, gridColSize[0],i,j);
                rst++;
            }
        }
    }
    return rst;

}
```
//并查集
#define DIR 2
int dir[DIR+1] = {-1,0, -1};
typedef struct {
    int x;
    int y;
}Point;
typedef struct {
    Point point;
    int rank;
}Node;

Node **g_set;
void FatherPrint(int row,int col) {
    int i,j;
    printf("\r\n set \r\n");
    for(i = 0; i < row; i++) {
        printf("\r\n");
        for(j = 0; j< col; j++) {
            printf("%d,%d,%d  ",g_set[i][j].point.x, g_set[i][j].point.y,g_set[i][j].rank);
        }
    }
    printf(" \r\n");
}

void  InitalSet(char** grid, int gridSize, int* gridColSize){
    int i,j;
    g_set = calloc(gridSize, sizeof(Node*));
    for(i = 0; i < gridSize; i++) {
        g_set[i] = calloc(gridColSize[0],sizeof(Node));
        for(j = 0; j< gridColSize[0]; j++) {
            if (grid[i][j] == '1') {
                g_set[i][j].point.x = i;
                g_set[i][j].point.y = j;
                g_set[i][j].rank = 0;
            }
        }
    }
}

Point FindFather(Point point) {
    Point a = point;
    while(g_set[a.x][a.y].point.x != a.x || g_set[a.x][a.y].point.y != a.y) {
        g_set[a.x][a.y].point = 
            g_set[g_set[a.x][a.y].point.x][g_set[a.x][a.y].point.y].point;
        a = g_set[a.x][a.y].point;

    }
    return a;
}
void Uninon(Point pointold,Point pointnew) {
    Point afather = FindFather(pointold);
    Point bfather = FindFather(pointnew);

    if(afather.x == bfather.x && afather.y == bfather.y) {
        return;
    }

    if(g_set[afather.x][afather.y].rank > g_set[bfather.x][bfather.y].rank) {
        g_set[bfather.x][bfather.y].point = afather;
    } else if (g_set[afather.x][afather.y].rank < g_set[bfather.x][bfather.y].rank) {
        g_set[afather.x][afather.y].point = bfather;
    }else {
        g_set[afather.x][afather.y].point = bfather;
        g_set[bfather.x][bfather.y].rank++;
    }
    

}
void PointPro(int i,int j, char** grid, int gridSize, int* gridColSize) {
    int loop;
    Point  pointold, pointnew; 
    for (loop = 0;loop < DIR; loop++) {
        pointold.x = i;
        pointold.y = j;
        pointnew.x = i + dir[loop];
        pointnew.y = j + dir[loop +1];
        if(pointnew.x >= 0 && pointnew.y >= 0) {
            if(grid[pointnew.x][pointnew.y] == '1') {
                //printf("hou qian %d %d,%d %d\r\n",pointold.x, pointold.y ,pointnew.x, pointnew.y); 
                Uninon(pointold,pointnew);
                //FatherPrint(gridSize,gridColSize[0]);    
            }
        }
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int rst = 0;
    int i, j, loop;

    //1 初始化
    InitalSet(grid, gridSize, gridColSize);    
    
    //2.合并
    for(i = 0; i < gridSize; i++) {
        for(j = 0; j< gridColSize[0]; j++) {
                if (grid[i][j] == '1') {
                    PointPro(i, j, grid, gridSize, gridColSize);
                }
            }
    }
    //3 统计
    for(i = 0; i < gridSize; i++) {
        for(j = 0; j< gridColSize[0]; j++) {
            if(grid[i][j] != '0' && g_set[i][j].point.x == i && g_set[i][j].point.y == j) {
                rst++;
            }
        }
    }

    return rst;
}