### 解题思路
采用广度优先搜索法解决这个问题。

      用数组q模拟队列操作，front为队头指针，rear为队尾指针，初始时front=rear=0。

      入队操作为 q[rear++]=cur;

      出队操作为 cur=q[front++]。
![截屏2020-02-05上午11.28.58.png](https://pic.leetcode-cn.com/89d5f24f989e788851bfcdf44849f4eeb79f35b83a5d87e68d6681311ed92603-%E6%88%AA%E5%B1%8F2020-02-05%E4%B8%8A%E5%8D%8811.28.58.png)


### 代码

```c
#define NUM 100

#define DIRECTION_NUM 4

typedef struct _Node{
    int x;
    int y;
    int counter;
}Node;

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    if(grid == NULL || gridSize == 0 || gridColSize == NULL)
    {
        return -1;
    }

    Node q[NUM] = {0};
    Node cur;
    int front = 0;
    int rear  = 0;

    int x = 0;
    int y = 0;
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    int rows = gridSize;
    int cols = gridColSize[0];

    int timeCounter = 0;

    int freshOrangeCounter = 0;
    int rottenOrangeCounter = 0;

    for(int i = 0;i < rows;i++)
    {
        for(int j = 0;j < cols;j++)
        {
            if(grid[i][j] == 1)
            {
                freshOrangeCounter++;
            }
            else if(grid[i][j] == 2)
            {
                rottenOrangeCounter++;
                q[rear].x = i;
                q[rear].y = j;
                q[rear++].counter = 0;//node enqueue
            }
        }
    }
    if(freshOrangeCounter == 0)
    {
        return 0;
    }

    if(rottenOrangeCounter == 0)
    {
        return -1;
    }

    while(rear != front)
    {
        cur = q[front++];//node dequeue

        if(freshOrangeCounter <= 0)
        {
            return timeCounter;
        }

        for(int i = 0;i < DIRECTION_NUM;i++)
        {
            x = cur.x + dx[i];
            y = cur.y + dy[i];
            if(x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1)
            {
                freshOrangeCounter--;
                q[rear].x = x;
                q[rear].y = y;
                /* The node count of the same layer is same */
                q[rear++].counter = cur.counter + 1;
                timeCounter = cur.counter + 1;
                grid[x][y] = 2;
            }
        }
    }
    return -1;
}
```