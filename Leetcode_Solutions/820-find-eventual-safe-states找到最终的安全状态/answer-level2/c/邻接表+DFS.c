### 解题思路
开始用的邻接矩阵来存边的信息，超时，改用邻接表存储，通过

### 代码

```c
#define MAX_VERTEX_NUM 10000

#define VERTEX_VISITED 0x1
#define VERTEX_CACHED  0x2
#define VERTEX_LOOP    0x4

struct vertex_node {
    int vertex;
    struct vertex_node *next;
};

struct vertex_data {
    unsigned char flag;
    struct vertex_node *next;
};

struct vertex_data vertex_table[MAX_VERTEX_NUM];

struct stack {
    int top;
    int size;
    int data[0];
};

void stack_push(struct stack *s, int vertex)
{
    if (s->top == s->size) {
        printf("stack full\n");
        return;
    }

    s->data[s->top] = vertex;
    s->top++;
}

int stack_pop(struct stack *s, int *vertex)
{
    if (s->top == 0)
        return -1;
    s->top--;
    *vertex = s->data[s->top];
    return 1;
}


int check_loop(struct stack *s, int head_vertex)
{
    int i;

    for (i = 0; i < s->top; i++) {
        if (s->data[i] == head_vertex)
            return 1;
    }

    return 0;
}

void dfs(struct stack *s, int vertex_num, int vertex)
{
    int i;
    int j;
    int ret;
    uint32_t head_vertex = 0;
    uint32_t tail_vertex = vertex;
    struct vertex_node *vnode;

    s->top = 0;

    while (1) {
        vertex_table[tail_vertex].flag |= VERTEX_VISITED;
        vnode = vertex_table[tail_vertex].next;
        while (vnode != NULL) {
            head_vertex = vnode->vertex;
            if (tail_vertex == head_vertex) {
                vertex_table[tail_vertex].flag |= VERTEX_LOOP;
                for (j = 0; j < s->top; j++) {
                    vertex_table[s->data[j]].flag |= VERTEX_LOOP;
                }
                return;
            }

            if ((vertex_table[head_vertex].flag & VERTEX_LOOP) != 0 || check_loop(s, head_vertex)) {
                vertex_table[tail_vertex].flag |= VERTEX_LOOP;
                for (j = 0; j < s->top; j++) {
                    vertex_table[s->data[j]].flag |= VERTEX_LOOP;
                }
                return;
            }

            if ((vertex_table[head_vertex].flag & (VERTEX_VISITED | VERTEX_CACHED)) == 0) {
                stack_push(s, tail_vertex);
                vertex_table[tail_vertex].flag |= VERTEX_CACHED;
                tail_vertex = head_vertex;
                break;
            }
            vnode = vnode->next;
        }

        if (vnode == NULL) {
            ret = stack_pop(s, &tail_vertex);
            if (ret < 0)
                return;

            vertex_table[tail_vertex].flag &= (~VERTEX_CACHED);
        }
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize, int* returnSize){
    int i;
    int j;
    int *res = NULL;
    struct stack *s = NULL;
    struct vertex_node *vnode;
    struct vertex_node **ppvnode;
    struct vertex_node *tmp_node;

    *returnSize = 0;
    if (graph == NULL || graphSize <= 0)
        return NULL;

    res = (int *)malloc(sizeof(int) * graphSize);
    s = (struct stack *)malloc(sizeof(struct stack) + sizeof(uint32_t) * graphSize);
    s->size = graphSize;

    memset(vertex_table, 0, sizeof(vertex_table));
    for (i = 0; i <graphSize; i++) {
        ppvnode = &vertex_table[i].next;
        for (j = 0; j < graphColSize[i]; j++) {
            vnode = (struct vertex_node *)malloc(sizeof(struct vertex_node));
            vnode->vertex = graph[i][j];
            vnode->next = NULL;
            *ppvnode = vnode;
            ppvnode = &vnode->next;
        }
    }

    for (i = 0; i < graphSize; i++) {
        if (vertex_table[i].flag == 0)
            dfs(s, graphSize, i);
    }

    free(s);

    j = 0;
    for (i = 0; i < graphSize; i++) {
        if ((vertex_table[i].flag & VERTEX_LOOP) == 0) {
            res[j++] = i;
        }
        vnode = vertex_table[i].next;
        while (vnode != NULL) {
            tmp_node = vnode;
            vnode = vnode->next;
            free(tmp_node);
        }
    }
    *returnSize = j;

    return res;
}
```