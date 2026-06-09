### 解题思路
此处撰写解题思路
经典队列 bfs， head为第一个可用元素前的黑洞，tail为最后一个可用元素。
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX 1000

struct Queue {
    struct TreeNode **arr;
    int head;
    int tail;
};

bool isEmpty(struct Queue *q)
{
    if (q->head && q->head == q->tail) {
        return true;
    }

    return false;
}

void CreateQueue(struct Queue *q)
{
    q->arr = calloc(1000, sizeof(struct TreeNode*));
    q->head = 0;
    q->tail = 0;
}

void Equeue(struct Queue *q, struct TreeNode *node)
{
    q->tail += 1;
    q->arr[q->tail] = node;
}

struct TreeNode* Dqueue(struct Queue *q)
{
    if (isEmpty(q)) {
        return NULL;
    }

    q->head += 1;
    return q->arr[q->head];
}

void print(struct Queue *q)
{
    int i = q->head + 1;
    while (i <= q->tail) {
        printf("%d ", q->arr[i]->val);
        i++;
    }
    printf("\n");
}

struct ListNode** bfs(struct TreeNode *root, int *returnSize)
{
    struct ListNode **res = calloc(MAX, sizeof(struct ListNode*));
    int res_index = 0;

    struct Queue *q = calloc(1, sizeof(struct Queue));
    CreateQueue(q);
    Equeue(q, root);

    while(!isEmpty(q)) {
        int curSize = q->tail - q->head;
        for (int i = 0; i < curSize; i++) {
            struct TreeNode *tmp = Dqueue(q);
            struct ListNode *pre;
            if (i == 0) {
                res[res_index] = calloc(1, sizeof(struct ListNode));
                res[res_index]->val = tmp->val;
                res[res_index]->next = NULL;
                pre = res[res_index];
                res_index++;
            }
            else {
                struct ListNode *t = calloc(1, sizeof(struct ListNode));
                t->val = tmp->val;
                t->next = NULL;
                pre->next = t;
                pre = pre->next;
            }

            if (tmp->left) {
                Equeue(q, tmp->left);
            }
            if (tmp->right) {
                Equeue(q, tmp->right);
            }
        }
    }

    *returnSize = res_index;
    return res;
}

struct ListNode** listOfDepth(struct TreeNode* tree, int* returnSize){
    if (tree == NULL) {
        return NULL;
    }

    struct ListNode **res = bfs(tree, returnSize);
    return res;
}
```