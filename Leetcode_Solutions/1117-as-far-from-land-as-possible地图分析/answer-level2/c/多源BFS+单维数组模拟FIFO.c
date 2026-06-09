### 解题思路
 
![image.png](https://pic.leetcode-cn.com/171932f475158935334f7a32d87a2837f3bd5a4b62246594d2f1fed6b7cfe352-image.png)
####第一个知识点：多源BFS
类似于树的寻找最大叶子节点深度，这是单源BFS
采用FIFO先入先出，level表示当前层次，每次遍历完该层，level++

把题目的陆地中比作树的root，只是有多个root，只需要初始的时候同时把所有的陆地push到0层，同时参与遍历，大家用共同的level表示海距离陆地的曼哈顿距离
以陆地作为源，进行BFS可以得到地图上的海洋距离周边陆地的最短距离，该海洋被遍历到后就不再参与遍历
BFS遍历图为了去重，通常用bool数组表示这个点已经访问过，这里只需要把grid[][]的值做原地修改即可

####第二个知识点：c语言里面的FIFO
我们只需要(x,y)表示下一次要访问的坐标，由于题目给定0<=x,y<=100<256
x,y可以通过 x<<8||y用一个unsinged short表示
最大队列长度：gridSize*gridSize


### 代码

```c


int maxDistance(int** grid, int gridSize, int* gridColSize) {
    typedef unsigned short u16;
#define POP(x,y)     \
    do {                \
        *x=queue[dequeue]>>8;  \
        *y=queue[dequeue++]&(~0xFF00);\
    } while(0)
#define PUSH(x,y) queue[enqueue++]=(x)<<8|(y)
    int enqueue = 0, dequeue = 0;
    u16 *queue = (u16*)malloc(gridSize*gridSize * 2);
    for (u16 i = 0; i < gridSize;i++) {
        for (int j = 0; j < gridSize;j++) {
            if (grid[i][j])PUSH(i, j);
        }
    }
    if (enqueue == 0 || enqueue == gridSize*gridSize)return -1;
    int dx[] = { 1,0,-1,0 };
    int dy[] = { 0,1,0,-1 };
    int level=-1;
    while (dequeue < enqueue) {
        level++;
        int curr_enqueue = enqueue;
        for (int i = dequeue; i < curr_enqueue; i++) {
            u16 x, y;
            POP(&x, &y);
            for (int j = 0; j < 4;j++) {
                int cx = x + dx[j];
                int cy = y + dy[j];
                if (cx < 0 || cy < 0 || cx >= gridSize || cy >= gridSize || grid[cx][cy])continue;
                PUSH(cx, cy);
                grid[cx][cy] = 2;
            }
        }
    }
    return level;
}

```