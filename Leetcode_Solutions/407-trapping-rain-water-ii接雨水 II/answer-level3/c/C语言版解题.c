参考其他解题思路，用BFS来实现
如果用队列+BFS，由于每次都要找最小值，这里会超时，见代码一
换成了最小堆+BFS来实现，通过，见代码二

**代码一**

```c
#define MAX_NUM 111

typedef struct {
    int x;
    int y;
    int height;
} Node;

Node g_list[MAX_NUM * MAX_NUM] = {0};
bool g_visited[MAX_NUM * MAX_NUM] = {false};
int g_dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int Compare(const void *value1, const void *value2)
{
    return ((Node *)value1)->height - ((Node *)value2)->height;
}

int trapRainWater(int** heightMap, int heightMapSize, int* heightMapColSize){
    int i;
    int head = 0;
    int tear = 0;
    int result = 0;
    Node topNode;
    Node nextNode;

    if (heightMapSize <= 0) {
        return 0;
    }

    (void)memset(g_visited, 0, sizeof(bool) * heightMapSize * heightMapColSize[0]);
    for (i = 0; i < heightMapSize; i++) {
        g_list[tear].x = 0;
        g_list[tear].y = i;
        g_list[tear].height = heightMap[i][0];
        tear++;
        g_list[tear].x = heightMapColSize[0] - 1;
        g_list[tear].y = i;
        g_list[tear].height = heightMap[i][heightMapColSize[0] - 1];
        tear++;
        g_visited[i * heightMapColSize[0]] = true;
        g_visited[i * heightMapColSize[0] + heightMapColSize[0] - 1] = true;
    }
    for (i = 1; i < heightMapColSize[0] - 1; i++) {
        g_list[tear].x = i;
        g_list[tear].y = 0;
        g_list[tear].height = heightMap[0][i];
        tear++;
        g_list[tear].x = i;
        g_list[tear].y = heightMapSize - 1;
        g_list[tear].height = heightMap[heightMapSize - 1][i];
        tear++;
        g_visited[i] = true;
        g_visited[(heightMapSize - 1) * heightMapColSize[0] + i] = true;
    }

    while (tear > head) {
        qsort(g_list + head, tear - head, sizeof(Node), Compare);
        topNode = g_list[head];
        head++;

        for (i = 0; i < 4; i++) {
            nextNode.x = topNode.x + g_dir[i][0];
            nextNode.y = topNode.y + g_dir[i][1];
            if (nextNode.x < 0 || nextNode.x >= heightMapColSize[0] || nextNode.y < 0 || nextNode.y >= heightMapSize) {
                continue;
            }
            if (g_visited[nextNode.y * heightMapColSize[0] + nextNode.x]) {
                continue;
            }
            g_visited[nextNode.y * heightMapColSize[0] + nextNode.x] = true;
            nextNode.height = heightMap[nextNode.y][nextNode.x];
            // if wall height is bigger than inner height, means can fill water
            if (nextNode.height < topNode.height) {
                result += topNode.height - nextNode.height;
            }
            g_list[tear].x = nextNode.x;
            g_list[tear].y = nextNode.y;
            // use the max height as the wall
            g_list[tear].height = nextNode.height > topNode.height ? nextNode.height : topNode.height;
            tear++;
        }
    }

    return result;
}
```

**代码二**

```c
#define MAX_NUM 111

typedef struct {
    int x;
    int y;
    int value;
} Node;

typedef struct {
    int maxSize;
    int size;
    Node *heap;
} TreeHeap;

bool g_visited[MAX_NUM * MAX_NUM] = {false};
int g_dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void InitHeap(TreeHeap *heap, int maxSize)
{
    heap->size = 0;
    heap->maxSize = maxSize;
    heap->heap = (Node *)malloc(sizeof(Node) * maxSize);
}

void FreeHeap(TreeHeap *heap)
{
    heap->size = 0;
    heap->maxSize = 0;
    if (heap->heap != NULL) {
        free(heap->heap);
    }
}

void ShiftUp(TreeHeap *heap, int pos)
{
    int father = 0;
    int currentPos = pos;
    Node tempValue;

    if (pos <= 0) {
        return;
    }

    do {
        father = (currentPos - 1) / 2;
        // compare father and currentPos
        if ((heap->heap[father]).value > (heap->heap[currentPos]).value) {
            tempValue = heap->heap[father];
            heap->heap[father] = heap->heap[currentPos];
            heap->heap[currentPos] = tempValue;
            currentPos = father;
        } else {
            break;
        }        
    } while(currentPos > 0);    
}

void ShiftDown(TreeHeap *heap, int pos)
{
    int leftChild = 0;
    int rightChild = 0;
    int switchPos = 0;
    int currentPos = pos;
    Node tempValue;

    if (pos >= heap->size) {
        return;
    }

    do {
        switchPos = currentPos;
        leftChild = currentPos * 2 + 1;
        if (leftChild >= heap->size) {
            break;
        }
        // compare left child and currentPos
        if ((heap->heap[leftChild]).value < (heap->heap[switchPos]).value) {
            switchPos = leftChild;
        }
        
        rightChild = (currentPos + 1) * 2;
        if (rightChild < heap->size) {
            // compare left child and switchPos
            if ((heap->heap[rightChild]).value < (heap->heap[switchPos]).value) {
                switchPos = rightChild;
            }
        }

        if (switchPos != currentPos) {
            tempValue = heap->heap[switchPos];
            heap->heap[switchPos] = heap->heap[currentPos];
            heap->heap[currentPos] = tempValue;
            currentPos = switchPos;
        } else {
            break;
        }
    } while(currentPos < heap->size);    
}

int getSize(TreeHeap *heap)
{
    return heap->size;
}

void PushHeap(TreeHeap *heap, Node *value)
{
    if (heap->size >= heap->maxSize) {
        return;
    }
    heap->heap[heap->size] = *value;
    heap->size++;
    ShiftUp(heap, heap->size - 1);
}

Node PopHeap(TreeHeap *heap)
{
    Node value = heap->heap[0];
    heap->size--;
    if (heap->size > 0) {
        heap->heap[0] = heap->heap[heap->size];
        ShiftDown(heap, 0);
    }

    return value;
}

int trapRainWater(int** heightMap, int heightMapSize, int* heightMapColSize){
    int i;
    int result = 0;
    Node nodeValue;
    Node nextNode;
    TreeHeap heap;

    if (heightMapSize <= 0) {
        return 0;
    }

    InitHeap(&heap, MAX_NUM * MAX_NUM);
    (void)memset(g_visited, 0, sizeof(bool) * heightMapSize * heightMapColSize[0]);
    for (i = 0; i < heightMapSize; i++) {
        nodeValue.x = 0;
        nodeValue.y = i;
        nodeValue.value = heightMap[i][0];
        PushHeap(&heap, &nodeValue);
        nodeValue.x = heightMapColSize[0] - 1;
        nodeValue.y = i;
        nodeValue.value = heightMap[i][heightMapColSize[0] - 1];
        PushHeap(&heap, &nodeValue);
        g_visited[i * heightMapColSize[0]] = true;
        g_visited[i * heightMapColSize[0] + heightMapColSize[0] - 1] = true;
    }
    for (i = 1; i < heightMapColSize[0] - 1; i++) {
        nodeValue.x = i;
        nodeValue.y = 0;
        nodeValue.value = heightMap[0][i];
        PushHeap(&heap, &nodeValue);
        nodeValue.x = i;
        nodeValue.y = heightMapSize - 1;
        nodeValue.value = heightMap[heightMapSize - 1][i];
        PushHeap(&heap, &nodeValue);
        g_visited[i] = true;
        g_visited[(heightMapSize - 1) * heightMapColSize[0] + i] = true;
    }

    while (heap.size > 0) {
        nodeValue = PopHeap(&heap);

        for (i = 0; i < 4; i++) {
            nextNode.x = nodeValue.x + g_dir[i][0];
            nextNode.y = nodeValue.y + g_dir[i][1];
            if (nextNode.x < 0 || nextNode.x >= heightMapColSize[0] || nextNode.y < 0 || nextNode.y >= heightMapSize) {
                continue;
            }
            if (g_visited[nextNode.y * heightMapColSize[0] + nextNode.x]) {
                continue;
            }
            g_visited[nextNode.y * heightMapColSize[0] + nextNode.x] = true;
            nextNode.value = heightMap[nextNode.y][nextNode.x];
            // if wall height is bigger than inner height, means can fill water
            if (nextNode.value < nodeValue.value) {
                result += nodeValue.value - nextNode.value;
            }
            // use the max height as the wall
            if (nextNode.value < nodeValue.value) {
                nextNode.value = nodeValue.value;
            }
            PushHeap(&heap, &nextNode);
        }
    }

    FreeHeap(&heap);

    return result;
}
```