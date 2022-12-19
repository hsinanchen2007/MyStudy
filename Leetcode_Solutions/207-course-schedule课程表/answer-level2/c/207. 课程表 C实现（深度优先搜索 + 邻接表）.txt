### 解题思路
    效率比本人前一题解邻接矩阵高不少。
    开始对这题很困惑，[0,1],[2,1],[1,2]的这种组合不行，先学0这样就能学1，就可以完成2。所以开始考虑的很复杂，想通过深搜 + 出度 + 入度剪枝，这题单纯只考察有向图判断环就比较简单了。
### 代码

```c
typedef struct head {
    int node;
    struct list* next;
} head;

void Insert(head** adjacency, int node, int insert)
{
    head* h = adjacency[node];
    head* newNode = (head*)malloc(sizeof(head));
    newNode->node = insert;
    newNode->next = NULL;
    if (!h) {
        adjacency[node] = newNode;
    } else {
        while (h->next) {
            h = h->next;
        }
        h->next = newNode;
    }
    return;
}

int** CreateGraph(int numCourses, int** prerequisites, int prerequisitesSize)
{
    head** adjacency = (head**)malloc(sizeof(head*) * numCourses);
    int mallocSize = sizeof(head) * numCourses;
    for (int i = 0; i < numCourses; i++) {
        adjacency[i] = NULL;
    }
    for (int i = 0; i < prerequisitesSize; i++) {
        Insert(adjacency, prerequisites[i][1], prerequisites[i][0]);
    }
    return adjacency;
}

bool dfs(int numCourses, int** adjacency, int* color, int node)
{
    if (color[node] == 1) {
        return false;
    }
    if (color[node] == -1) {
        return true;
    }
    color[node] = 1;
    head* head = adjacency[node];
    while (head) {
        if (!dfs(numCourses, adjacency, color, head->node)) {
            return false;
        }
        head = head->next;
    }
    color[node] = -1;
    return true;
}

inline void Free(int numCourses, int** adjacency, int* color)
{
    for (int i = 0; i < numCourses; i++) {
        head* p = adjacency[i];
        while (p) {
            head* pre = p;
            p = p->next;
            free(pre);
        }
    }
    free(adjacency);
    free(color);
    return;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize)
{
    if (!prerequisites || prerequisitesSize <= 0) {
        return true;
    }
    int** adjacency = CreateGraph(numCourses, prerequisites, prerequisitesSize);
    int mallocSize = sizeof(int) * numCourses;
    int* color = (int*)malloc(mallocSize);
    memset(color, 0, mallocSize);
    for (int i = 0; i < numCourses; i++) {
        if (!dfs(numCourses, adjacency, color, i)) {
            Free(numCourses, adjacency, color);
            return false;
        }
    }
    Free(numCourses, adjacency, color);
    return true;
}
```