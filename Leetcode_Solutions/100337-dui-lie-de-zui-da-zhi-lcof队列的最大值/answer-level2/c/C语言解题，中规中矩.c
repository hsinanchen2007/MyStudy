执行用时 : 208 ms , 在所有 C 提交中击败了 64.29% 的用户 内存消耗 : 42.9 MB , 在所有 C 提交中击败了 100.00% 的用户

```
typedef struct {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} MaxQueue;

MaxQueue *g_maxQ = NULL;
MaxQueue* maxQueueCreate()
{
    g_maxQ = (MaxQueue *)malloc(sizeof(MaxQueue));
    g_maxQ->head = NULL;
    g_maxQ->tail = NULL;
    return g_maxQ;
}

int maxQueueMax_value(MaxQueue* obj)
{
    if (obj->head == NULL) {
        return -1;
    } else {
        Node *node = obj->head;
        int max = node->value;
        while (node) {
            max = (node->value > max) ? (node->value) : max;
            node = (Node *) node->next;
        }
        return max;
    }
}

void maxQueuePush_back(MaxQueue* obj, int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->value = value;
    if (obj->head == NULL) {
        obj->head = node;
    }
    if (obj->tail == NULL) {
        obj->tail = node;
    } else {
        obj->tail->next = (struct Node *) node;
        obj->tail = node;
    }
}

int maxQueuePop_front(MaxQueue* obj)
{
    if (obj->head == NULL) {
        return -1;
    } else {
        Node *node = obj->head;
        int value = node->value;
        obj->head = (Node *) node->next;
        if (obj->head == NULL) {
            obj->tail = NULL;
        }
        free(node);
        return value;
    }
}

void maxQueueFree(MaxQueue* obj)
{
    Node *node = obj->head;
    while (node) {
        obj->head = (Node *) node->next;
        free(node);
        node = obj->head;
    }
    free(g_maxQ);
}
```
