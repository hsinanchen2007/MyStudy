### 解题思路
二叉树层序遍历，额外需要一个元素来记录深度。

由于全部遍历完之前无法知道准确的深度，可以使用2个策略：
1. 分两次遍历，第一次构造堆并知道准确的最大深度，第二次创建链表数组；
2. 先分配一个链表数组，当层数超过已分配的大小时重新分配。

以下代码采用策略1.


### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct NodeLevel {
    struct TreeNode *node;
    int depth;
};

typedef struct Heap {
    int start;
    int end;
    int size;
    struct NodeLevel data[];
} heap;

static heap* buildHeap(int size, heap* oldHeap, int oldSize)
{
    heap *p = malloc(sizeof(heap) + size * sizeof(struct NodeLevel));
    if (p == NULL) exit(1);

    p->start = 0;
    p->end = 0;
    p->size = size;
    if (oldHeap) {
        p->start = oldHeap->start;
        p->end = oldHeap->end;
        memcpy(p->data, oldHeap->data, oldSize * sizeof(struct NodeLevel));
        free(oldHeap);
    }

    return p;
}

static heap* push(heap *h, struct TreeNode *node, int depth) {
    if (h->end < h->size) {
        if (node != NULL) {
            h->data[h->end].node = node;
            h->data[h->end].depth = depth;
            h->end++;
        }
    } else {
        h = push(buildHeap(((h->size)<<1), h, h->size), node, depth);
    }
    return h;
}

static struct NodeLevel* pop(heap *h) {
    struct NodeLevel *ret = &(h->data[h->start]);
    if (h->start < h->end) {
        h->start++;
        return ret;
    } else {
        return NULL;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** listOfDepth(struct TreeNode* tree, int* returnSize){
    struct NodeLevel *p;
    heap *heap = buildHeap(1024, NULL, 0);
    struct ListNode **ret;
    struct ListNode *floor;
    int currentFloor = -1;
    //push root node
    heap = push(heap, tree, 0);
    while ((p = pop(heap)) != NULL) {
        heap = push(heap, p->node->left, p->depth + 1);
        heap = push(heap, p->node->right, p->depth + 1);
        *returnSize = p->depth + 1;
    }

    ret = malloc(*returnSize * sizeof(void *));
    memset(ret, 0, *returnSize * sizeof(void *));

    heap->start = 0;
    while ((p = pop(heap)) != NULL) {
        if (currentFloor != p->depth) {
            currentFloor = p->depth;
            floor = ret[currentFloor] = malloc(sizeof(struct ListNode));
        } else {
            floor->next = malloc(sizeof(struct ListNode));
            floor = floor->next;
        }
        if (floor == NULL) {
            exit(1);
        } else {
            floor->next = NULL;
        }

        floor->val = p->node->val;
    }

    return ret;
}
```