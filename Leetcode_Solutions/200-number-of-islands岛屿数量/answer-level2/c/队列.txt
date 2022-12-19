### 解题思路
这个处理思路和二叉树遍历很相似，弹出节点的同时，压入该节点的关联节点，直到队列为空

### 代码

```c
/*遍历每个节点，如果该节点为1，并且没被遍历过*/
/* 存储当前点的坐标和值*/
int IsExist[500][500] = {0};

typedef struct {
    int x;
    int y;
    char val;
}Island;
typedef struct {
    int front;
    int rear;
    int size;
    Island data[500];
}Quene;
/*rear加 front删*/
void Init(Quene* q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    memset(q->data, 0, sizeof(Island) * 500);
}
int Push(Quene* q, Island* data) {
    if(q == NULL || data == NULL || q->size >= 500) {
        return -1;
    }
    if(q->rear < 0){
        q->front = 0;
    }
    q->rear++;
    q->rear = q->rear % 500;
    memcpy(&q->data[q->rear], data, sizeof(Island));
    q->size++;
    return 0;
}

int Pop(Quene* q) {
    if(q == NULL || q->size <=0) {
        return -1;
    }
    //memcpy(*data, q->data[q->front], sizeof(Island));
    q->front++;
    q->front = q->front % 500;
    q->size--;
    return 0;
}

void SetIsland(Island* data,int i, int j, int val) {
    data->x = i;
    data->y = j;
    data->val = val;
    return;
}


int numIslands(char** grid, int gridSize, int* gridColSize){
    if(grid == NULL || gridSize == 0 || gridColSize == NULL) {
        return 0;
    }
    for(int i = 0; i < 500; i++){
        for(int j = 0; j <500; j++) {
            IsExist[i][j] = 0;
        }
    }
    int IslandNum = 0;
    Quene q;
    Init(&q);
    for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < gridColSize[i]; j++) {
            if(grid[i][j] == '1' &&  IsExist[i][j] == 0){
                //printf("IN i is %d, j is %d\n",i,j);
                IslandNum ++;
                IsExist[i][j] = 1;
                Island data;
                SetIsland(&data, i, j, grid[i][j]);
                Push(&q, &data);
                while(q.size != 0) {
                    int cur_size = q.size;
                    while(cur_size > 0){
                        int i = q.data[q.front].x;
                        int j = q.data[q.front].y;
                        if(i-1 >=0 && grid[i-1][j] == '1' && IsExist[i-1][j] == 0) {
                            //printf("i is %d, j is %d\n",i-1,j);
                            IsExist[i-1][j] = 1;
                            SetIsland(&data, i-1, j, grid[i-1][j]);
                            Push(&q, &data);                           
                        }
                        if(i+1 <gridSize && grid[i+1][j] == '1' && IsExist[i+1][j] == 0) {
                            //printf("i is %d, j is %d\n",i+1,j);
                            IsExist[i+1][j] = 1;
                            SetIsland(&data, i+1, j, grid[i+1][j]);
                            Push(&q, &data);                           
                        }
                        if(j-1 >=0 && grid[i][j-1] == '1' && IsExist[i][j-1] == 0) {
                            //printf("i is %d, j is %d\n",i,j-1);
                            IsExist[i][j-1] = 1;
                            SetIsland(&data, i, j-1, grid[i][j-1]);
                            Push(&q, &data);                           
                        }
                        if(j+1 < gridColSize[i] && grid[i][j+1] == '1' && IsExist[i][j+1] == 0) {
                            //printf("i is %d, j is %d\n",i,j+1);
                            IsExist[i][j+1] = 1;
                            SetIsland(&data, i, j+1, grid[i][j+1]);
                            Push(&q, &data);                           
                        }
                        cur_size--;
                        Pop(&q);
                        //printf("size is %d\n",q.size);
                    }
                }
            }
        }
    }
    return IslandNum;
}



```