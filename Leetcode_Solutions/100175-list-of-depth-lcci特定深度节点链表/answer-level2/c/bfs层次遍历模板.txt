```
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

#define MAX 10000

typedef struct {
    struct TreeNode *data[MAX];
    int head;
    int tail;
}Queue;

Queue *create() {
    Queue *q = malloc(sizeof(Queue));
    q->head = q->tail = 0;
    return q;
}

bool empty(Queue *q) {
    return q->head == q->tail;
}

void EQueue(Queue *q, struct TreeNode *node) {
    q->tail++;
    q->data[q->tail] = node;
}

struct TreeNode *DQueue(Queue *q) {
    q->head++;
    struct TreeNode *res = q->data[q->head];
    if (q->head == q->tail) {
        q->head = 0;
        q->tail = 0;
    }
    return res;
}

struct ListNode** bfs(struct TreeNode *root, int *returnSize) {
    Queue *q = create();
    struct ListNode **ans = malloc(sizeof(struct ListNode *) * MAX);
    int ansSize = 0;
    EQueue(q, root);
    while (!empty(q)) {
        int curSize = q->tail - q->head;
        struct ListNode *pre = NULL;
        for (int i = 0; i < curSize; ++i) {
            struct TreeNode *tmp = DQueue(q);
            if (i == 0) {
                ans[ansSize] = malloc(sizeof(struct ListNode)); // head of each list
                ans[ansSize]->val = tmp->val;
                ans[ansSize]->next = NULL;
                pre = ans[ansSize];
            } else {
                struct ListNode *newListNode = malloc(sizeof(struct ListNode));
                newListNode->val = tmp->val;
                newListNode->next = NULL;
                pre->next = newListNode;
                pre = pre->next;
            }
            if (tmp->left != NULL) {
                EQueue(q, tmp->left);
            }
            if (tmp->right != NULL) {
                EQueue(q, tmp->right);
            }
        }
        ++ansSize;
    }
    // printf("ansSize: %d\n", ansSize);
    *returnSize = ansSize;
    return ans;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** listOfDepth(struct TreeNode* tree, int* returnSize){
    if (tree == NULL) {
        return NULL;
    }
    return bfs(tree, returnSize);
}
```
