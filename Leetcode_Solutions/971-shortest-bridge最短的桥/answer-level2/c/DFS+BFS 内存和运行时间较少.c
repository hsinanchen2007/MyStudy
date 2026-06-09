### 解题思路
第一步：dfs将第一个的岛屿元素全部标记出来，并顺序入队；
第二步：bfs遍历队内各元素，将未标记元素标记并入队，step++;
第三步：找到新的元素为1即为新岛屿，step++返回即可。

### 代码

```c
#define FOUND      2
#define DIRECTIONS 4
#define MAXSIZE    10000

// 定义岛屿元素结构体
typedef struct {
    int x;
    int y;
    int step;
}items;

typedef struct {
    items data[MAXSIZE];
    int front;
    int rear;
    int size;
}my_queue;

static my_queue g_queue = {0};
static int g_xshift[DIRECTIONS] = {-1, 1, 0, 0};
static int g_yshift[DIRECTIONS] = {0, 0, -1, 1};

void init(my_queue *queue)
{
    if (queue == NULL)
        return;

    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;

    return;
}

bool is_empty(my_queue *queue)
{
    if (queue == NULL)
        return false;

    return (queue->size == 0);
}

bool is_full(my_queue *queue)
{
    if (queue == NULL)
        return false;

    return (queue->size == MAXSIZE);
}

void en_queue(my_queue *queue, items item)
{
    if (queue == NULL)
        return;

    if (is_full(queue))
        return;
    if (queue->front == -1)
        queue->front++;
    queue->rear++;
    queue->rear %= MAXSIZE;
    queue->data[queue->rear] = item;
    queue->size++;

    return;
}

items de_queue(my_queue *queue)
{
    items data = {0};
    if (queue == NULL)
        return data;

    if (is_empty(queue))
        return data;
    
    data = queue->data[queue->front];
    queue->front++;
    queue->front %= MAXSIZE;
    queue->size--;

    return data;
}

int get_size(my_queue *queue)
{
    if (queue == NULL)
        return -1;

    return queue->size;
}

// DFS寻找第一个岛屿元素，并入队
void dfs(int ** A, int size, int x, int y)
{
    int i;
    items data = {0};

    if (x < 0 || x >= size || y < 0 || y >= size || A[x][y] != 1)
        return;
    
    data.x = x;
    data.y = y;
    data.step = 0;
    en_queue(&g_queue, data);
    A[x][y] = FOUND;

    for (i = 0; i < DIRECTIONS; i++)
        dfs(A, size, x + g_xshift[i], y + g_yshift[i]);

    return;
}

int shortestBridge(int** A, int ASize, int* AColSize){
    int i;
    int j;
    int step = 1;
    int find = 0;

    init(&g_queue);

    for (i = 0; i < ASize; i++) {
        for (j = 0; j < ASize; j++) {
            if (A[i][j] == 1) {
                dfs(A, ASize, i, j);
                find = 1;
                break;
            }
        }
        if (find == 1)
            break;
    }

    while (!is_empty(&g_queue)) {
        int size = get_size(&g_queue);
        while (size-- > 0) {
            items data = de_queue(&g_queue);
            for (i = 0; i < DIRECTIONS; i++) {
                int newx = data.x + g_xshift[i];
                int newy = data.y + g_yshift[i];
                bool marked = newx < 0 || newx >= ASize || newy < 0 || newy >= ASize || A[newx][newy] == FOUND;
                if (marked)
                    continue;
                if (A[newx][newy] == 1)
                    return data.step;

                items newdata = {0};
                newdata.x = newx;
                newdata.y = newy;
                newdata.step = data.step + 1;
                en_queue(&g_queue, newdata);
                A[newx][newy] = FOUND;
            }
        }
    }

    return step;
}
```