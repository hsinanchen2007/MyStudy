
实现一个简单的带有优先级的队列，存放链表。 链表首元素通过比较器比较val，作为优先级。
优先队列是用于保障 链表的存入速度+首元素的提取速度是局部优化过的。比暴力法能好一些。

核心函数mergeKLists_methodPrioQueue()

PriorityQueue简介：

    PriorityQueue能保证每次取出的元素都是队列中权值最小的。使用比较器实现权值比较。
    PriorityQueue通过完全二叉树（complete binary tree）实现的小顶堆（任意一个非叶子节点的权值，都不大于其左右子节点的权值）.
    完全二叉树,意味着可以通过数组来作为PriorityQueue的底层实现。
    PriorityQueue 资料参考 https://www.cnblogs.com/CarpenterLee/p/5488070.html

```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
struct ListNode {
    int val;
    struct ListNode *next;
}; */

typedef int (*PQ_COMPARE)(void *element1, void *element2);
typedef struct _PRIO_QUEUE {
    int used;
    int count;
    void **p;
    PQ_COMPARE compare;
}PRIO_QUEUE;

void PriorityQueue_Destory(PRIO_QUEUE * queue) {
    if (queue == NULL) {
        return;
    }
    if (queue->p != NULL) {
        free(queue->p);
    }
    free(queue);
}

PRIO_QUEUE *PriorityQueue_Create(PQ_COMPARE compare, int count) {
    PRIO_QUEUE * queue;
    if (compare == NULL || count <= 0) {
        return NULL;
    }
    queue = calloc(sizeof(PRIO_QUEUE), 1);
    if (queue == NULL) {
        return NULL;
    }
    queue->p = calloc(sizeof(void *), count);
    if (queue->p == NULL) {
        PriorityQueue_Destory(queue);
        return NULL;
    }
    queue->compare = compare;
    queue->count = count;
    return queue;
}

#define PQ_VAL(queue, index) ((queue)->p[(index)])

static inline void _shiftUp(PRIO_QUEUE *queue,  int child, void *element) {
    while (child > 0) {
        int parent = (child-1)>>1; // parent = (child-1)/2
        void* parentVal = PQ_VAL(queue, parent);
        if (queue->compare(parentVal, element) <= 0) { // compare
            break;
        }
        // parent to child, swap(child, parent) or parent->child;
        PQ_VAL(queue, child) = PQ_VAL(queue, parent);
        // keep check parent
        child = parent;
    }
    PQ_VAL(queue, child) = element;
}

static inline int PriorityQueue_Push(PRIO_QUEUE *queue, void *element) {
    if (queue->used >= queue->count) {
        int growSize = 65536;
        void **p = (void **)realloc(queue->p, sizeof(void *) * (queue->count + growSize));
        if (p == NULL) {
            return -1;
        }
        queue->p = p;
        queue->count += growSize;
    }
    PQ_VAL(queue, queue->used) = element;
    queue->used++;
    if (queue->used > 1){
        _shiftUp(queue,  queue->used-1, element);
    }
    return 0;
}

static inline void _shiftDown(PRIO_QUEUE *queue,  int parent, void *element) {
    // child is also mean left.
    int child, size;
    // find child to store element.
    size = queue->used;
    while(parent < size) {
        child = (parent<<1)+1; // default is left child (parent*2+1)
        // no valid child,break;
        if (child >= size ){
            break;
        }
        if (child + 1 < size && queue->compare(PQ_VAL(queue, child), PQ_VAL(queue, child+1))>0){
            child += 1; // left > right, right is min, set child to right.
        }
        // compare parent vs min_child
        if (queue->compare(PQ_VAL(queue, child), element)>=0) {
            break;
        }
        PQ_VAL(queue, parent) = PQ_VAL(queue, child);
        parent = child;
    }
    PQ_VAL(queue, parent) = element;
}

static inline int PriorityQueue_Pop(PRIO_QUEUE *queue, void **element) {
    void *last;
    if (queue->used == 0 || element == NULL) {
        return -1;
    }
    *element = PQ_VAL(queue,0);
    queue->used--;
    if(queue->used != 0){
        _shiftDown(queue, 0, PQ_VAL(queue,queue->used));
    }
    return 0;
}

int PriorityQueue_Top(PRIO_QUEUE *queue, void **element) {
    if (queue->used == 0) {
        return -1;
    }
    *element = PQ_VAL(queue,0);
    return 0;
}

static inline int PriorityQueue_IsEmpty(PRIO_QUEUE *queue) {
    return (queue->used == 0) ? 1 : 0;
}

void Display_ListNode(struct ListNode * list, const char* prefix);
#define NODE_VAL(node) (((struct ListNode *)node)->val)

static void Display_QueueValues(PRIO_QUEUE *queue, const char* prefix) {
    int line_count = 1, end_val = line_count;
    printf("%s\n", prefix);
    for (int i =0; i < queue->used; ) {
        for ( ;i < end_val && i < queue->used; i++) {
            printf(" %d ", NODE_VAL(queue->p[i]));
        }
        printf("\n");
        line_count *= 2;
        end_val += line_count;
    }
    for (int i =0; i < queue->used; i++) {
        char prefix[64];
        sprintf(prefix, "%d = ", i);
        Display_ListNode((struct ListNode *)queue->p[i], prefix);
    }
}

// 比较函数，只比较各链表的第一个元素数值
static int node_compare(void *element1, void *element2)
{
    return (NODE_VAL(element1) > NODE_VAL(element2)) ? 1 : (-1);
}

struct ListNode* mergeKLists_methodPrioQueue(struct ListNode** lists, int listsSize)
{
// dummy为一个虚的链表头，用于输出结果， tail始终指向输出结果的尾部。
    struct ListNode dummy = {0, NULL};
    struct ListNode *tail = &dummy;
// 创建优先队列，设置比较函数，以及初始大小
    PRIO_QUEUE *queue = PriorityQueue_Create(node_compare, 0x10000);
// 各链表入队。
    for(int i =0; i < listsSize; i++) {
// 测试用例有坑，如果是空的链表，那就放过它吧。
        if (lists[i] != NULL) {
            PriorityQueue_Push(queue, lists[i]);
        }
    }
// 队列不空，排序不止
    while (!PriorityQueue_IsEmpty(queue)) {
        struct ListNode *cur;
        //Display_QueueValues(queue, "before pop.");
// 取出一个元素最小的链表
        PriorityQueue_Pop(queue, (void **)&cur);
        //Display_QueueValues(queue, "after pop.");
// 取出之后链表是空的？ 那就没什么可以继续的了。串到输出链表就好了。
        if(PriorityQueue_IsEmpty(queue)){
            tail->next = cur;
            break;
        }
// 被取出链表还有后继元素？ 那就继续将它的后继元素开头的链表推入队列吧。
        if (cur->next != NULL) {
            PriorityQueue_Push(queue, cur->next);
        }
// 当前取出的第一个元素，当然要加入到输出链表。
        tail->next = cur;
        tail = tail->next;
    }
// 释放资源是个好习惯
    PriorityQueue_Destory(queue);
    return dummy.next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    //return mergeKLists_methodFindMinHeader(lists, listsSize);
    return mergeKLists_methodPrioQueue(lists, listsSize);
}

static inline struct ListNode* copyNode(struct ListNode* node) {
    struct ListNode *ret = (struct ListNode *)malloc(sizeof(struct ListNode));
    ret->val = node->val;
    ret->next = NULL;
    return ret;
}

struct ListNode *createTestListNode(int len, int max_start, int max_step) {
    struct ListNode node, *ret, *tail;
    node.val = rand() % max_start;
    ret = tail = copyNode(&node);
    for (int i = i; i < len; i++) {
        node.val += rand() % max_step;
        tail->next = copyNode(&node);
        tail = tail->next;
    }
    return ret;
}

struct ListNode **createTestList(int row, int max_col, int max_start, int max_step) {
    struct ListNode **ret = (struct ListNode **) calloc(sizeof(struct ListNode *), row);
    for (int i = 0; i < row; i++) {
        int col = rand() % max_col;
        if (col <= 0) {
            col = 1;
        }
        ret[i] = createTestListNode(col, max_start, max_step);
    }
    return ret;
}

void Display_ListNode(struct ListNode * list, const char* prefix) {
    printf("%s [", prefix);
    for (struct ListNode *node = list; node != NULL; node = node->next) {
        printf("%d, ", node->val);
    }
    printf("],\n");
}

void Display_ListNodeList(struct ListNode **list, int size, const char* prefix) {
    printf("%s [ \n", prefix);
    for (int i = 0; i < size; i++) {
        Display_ListNode(list[i], "");
    }
    printf("]\n");
}

int mergeKLists_tester(void)
{
    int row;
    struct ListNode *ret, **input;
    srand(time(NULL));
    row = 4;
    input = createTestList(row, 5, 10, 10);
    Display_ListNodeList(input, row, "input = ");
    ret = mergeKLists(input, row);
    if (ret != NULL) {
        Display_ListNode(ret, "result = ");
    }
    return 0;
}

```
