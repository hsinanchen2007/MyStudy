### 解题思路
定义一个海洋到所有陆地中的最小距离是“海洋到陆地的距离”。
题目要求找到一个海洋，此海洋到陆地的距离是最大的。
这个最大距离其实也就是从陆地出发到达最远海洋区域的距离。
因此问题转化为BFS，并且出发点有多个。
为什么出发点有多个呢？如果定义每次从一个陆地扩散一圈为“度”增加一，那么我们有理由相信被其他陆地扩散而增加的“度”，在本题目中对陆地到海洋最远距离的求取是“等效的”。
### 代码

```c
//定义节点
struct area{
    int x;
    int y;
    int distance;
};
//定义一个队列
struct queue {
    struct area* front;
    struct area* rear;
    struct area* areas;
    int count;

};
int checkLeftIsOcean(int** grid,struct area* area, int gridSize)
{
    int x = area->x - 1;
    int y = area->y;
    if (x < 0) {
        return 0;
    }
    if ((*((*(grid + x)) + y)) == 1) {
        return 0;
    }
    return 1;
}
int checkRightIsOcean(int** grid,struct area* area, int gridSize)
{
    int x = area->x + 1;
    int y = area->y;
    if (x >= gridSize) {
        return 0;
    }
    if ((*((*(grid + x)) + y)) == 1) {
        return 0;
    }
    return 1;
}
int checkUpIsOcean(int** grid,struct area* area, int gridSize)
{
    int x = area->x;
    int y = area->y - 1;
    if (y < 0) {
        return 0;
    }
    if ((*((*(grid + x)) + y)) == 1) {
        return 0;
    }
    return 1;
}
int checkDownIsOcean(int** grid,struct area* area, int gridSize)
{
    int x = area->x;
    int y = area->y + 1;
    if (y >= gridSize) {
        return 0;
    }
    if ((*((*(grid + x)) + y)) == 1) {
        return 0;
    }
    return 1;
}
void checkIsOceanAndAddArea(int** grid,struct area* area, int gridSize, 
        struct queue* que, int* maxDistance)
{
    //扩散时分为上下左右
    if (checkLeftIsOcean(grid, area, gridSize) == 1) {
        que->rear->x = area->x - 1;
        que->rear->y = area->y;
        que->rear->distance = area->distance + 1;
        que->count++;
        //填海造陆
        *((*(grid + que->rear->x)) + que->rear->y) = 1;
        if (*maxDistance < que->rear->distance) {
            *maxDistance = que->rear->distance;
        }
        que->rear = ((struct area*)(que->rear)) + 1;
    }
    if (checkRightIsOcean(grid, area, gridSize) == 1) {
        que->rear->x = area->x + 1;
        que->rear->y = area->y;
        que->rear->distance = area->distance + 1;
        que->count++;
        //填海造陆
        *((*(grid + que->rear->x)) + que->rear->y) = 1;
        if (*maxDistance < que->rear->distance) {
            *maxDistance = que->rear->distance;
        }
        que->rear = ((struct area*)(que->rear)) + 1;
    }
    if (checkUpIsOcean(grid, area, gridSize) == 1) {
        que->rear->x = area->x;
        que->rear->y = area->y - 1;
        que->rear->distance = area->distance + 1;
        que->count++;
        //填海造陆
        *((*(grid + que->rear->x)) + que->rear->y) = 1;
        if (*maxDistance < que->rear->distance) {
            *maxDistance = que->rear->distance;
        }
        que->rear = ((struct area*)(que->rear)) + 1;
    }
    if (checkDownIsOcean(grid, area, gridSize) == 1) {
        que->rear->x = area->x;
        que->rear->y = area->y + 1;
        que->rear->distance = area->distance + 1;
        que->count++;
        //填海造陆
        *((*(grid + que->rear->x)) + que->rear->y) = 1;
        if (*maxDistance < que->rear->distance) {
            *maxDistance = que->rear->distance;
        }
        que->rear = ((struct area*)(que->rear)) + 1;
    }
    
    return;
}
//所谓填海造陆就是着色
int maxDistance(int** grid, int gridSize, int* gridColSize){
    int maxDistance = 0;
    //创建一个队列用来盛放bfs的节点
    struct queue que = {0};
    que.areas = (struct area*)malloc(sizeof(struct area) * gridSize * gridSize);
    memset(que.areas, 0, sizeof(struct area) * gridSize * gridSize);
    que.front = que.areas;
    que.rear = que.areas;
    if ((NULL == grid) || (NULL == *grid) || (gridSize == 0) 
        || (gridColSize == NULL) || (gridColSize == 0) || (gridSize != *gridColSize)) {
            return -1;
    }
    //遍历数组，将陆地都放到队列内，并且将distance置为0
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j<gridSize; j++) {
            //printf("%d",*((*(grid + i)) + j));
            if (*((*(grid + i)) + j) == 1) {
                que.rear->x = i;
                que.rear->y = j;
                que.rear->distance = 0;
                que.rear = ((struct area*)que.rear) + 1;
                que.count ++;
            }
        }
    }
    if ((que.count == 0) || (que.count == gridSize * gridSize)) {
        return -1;
    }
    //遍历队列中的所有节点，查找该节点四周区域如果是海洋，distance加1放入队列，加1的同时记录下最大的距离
    while ((que.count != 0) || (que.front != que.rear)) {
        //检查front的四周如果是海洋，distance加1,并且放入队列
        checkIsOceanAndAddArea(grid,que.front,gridSize,&que,&maxDistance);
        que.front = ((struct area *)(que.front)) + 1;
        que.count--;
    }
    free(que.areas);
    que.areas = NULL;
    return maxDistance;
}
```