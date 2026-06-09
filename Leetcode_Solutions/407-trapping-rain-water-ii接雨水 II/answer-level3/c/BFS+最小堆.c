### 解题思路
BFS，最小堆

### 代码

```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))
typedef struct {
    int x;
    int y;
    int h;
} HeapElement;

typedef struct {
    HeapElement *data;
    int size;
} MinHeap;

MinHeap *CreateMinHeap(int size)
{
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    heap->data = (HeapElement *)malloc(sizeof(HeapElement) * (size + 1));
    heap->size = 0;
    heap->data[0].h = INT_MIN;
    return heap;
}

void InsertToHeap(MinHeap *heap, int h, int x, int y)
{
    int i = ++heap->size;
    for (; h < heap->data[i / 2].h; i /= 2) {
        heap->data[i] = heap->data[i / 2];
    }
    heap->data[i].x = x;
    heap->data[i].y = y;
    heap->data[i].h = h;
}

HeapElement DeleteFromHeap(MinHeap *heap)
{
    HeapElement minElement = heap->data[1];
    HeapElement last = heap->data[heap->size];
    int i,child;

    heap->size--;
    for (i = 1; i * 2 <= heap->size; i = child) {
        child = i * 2;
        if (child < heap->size && heap->data[child].h > heap->data[child + 1].h) {
            child++;
        }

        if (last.h < heap->data[child].h) {
            break;
        } else {
            heap->data[i] = heap->data[child];
        }
    }

    heap->data[i] = last;
    return minElement;
}

int trapRainWater(int** heightMap, int heightMapSize, int* heightMapColSize)
{
    int i = 0;
    int j = 0;
    int ans = 0;
    MinHeap *heap = NULL;
    int **visit = NULL;
    int rows = heightMapSize;
    int cols = *heightMapColSize;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int x, y;

    if (heightMap == NULL || heightMapSize <= 2 || heightMapColSize[0] <= 2) {
        return 0;
    }

    heap = CreateMinHeap(10240);

    visit = (int **)malloc(sizeof(int *) * rows);
    for (i = 0; i < rows; i++) {
        visit[i] = (int *)malloc(sizeof(int) * cols);
        memset(visit[i], 0, sizeof(int) * cols);
    }

    for (j = 0; j < cols; j++) {
        InsertToHeap(heap, heightMap[0][j], 0, j);
        InsertToHeap(heap, heightMap[rows - 1][j], rows - 1, j);
        visit[0][j] = 1;
        visit[rows - 1][j] = 1;
    }

    for (i = 1; i < rows - 1; i++) {
        InsertToHeap(heap,  heightMap[i][0], i, 0);
        InsertToHeap(heap, heightMap[i][cols - 1], i, cols - 1);
        visit[i][0] = 1;
        visit[i][cols - 1] = 1;
    }

    while (heap->size > 0) {
        HeapElement top = DeleteFromHeap(heap);
        for (i = 0; i < 4; i++) {
            x = top.x + dir[i][0];
            y = top.y + dir[i][1];
            if (x >= 0 && x < rows && y >= 0 && y < cols && visit[x][y] == 0) {
                visit[x][y] = 1;
                InsertToHeap(heap,  MAX(top.h, heightMap[x][y]), x, y);
                ans += MAX(0, top.h - heightMap[x][y]);
            }
        }
    }

    return ans;
}
```