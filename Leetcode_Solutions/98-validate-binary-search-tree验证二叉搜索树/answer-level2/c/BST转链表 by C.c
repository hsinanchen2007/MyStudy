### 解题思路
1. BST的中序遍历刚好是升序。
2. 因此按中序遍历保存为链表，检查链表是否有序

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



struct ListNode* formatBST2List(struct TreeNode* root, struct ListNode **last) {
    struct ListNode *left = NULL;
    struct ListNode *leftLast = NULL;
    if (root->left) {
        left = formatBST2List(root->left, &leftLast);
    }

    struct ListNode* mid = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (mid == NULL) {
        return NULL;
    }
    mid->val = root->val;
    mid->next = NULL;

    struct ListNode *right = NULL;
    struct ListNode *rightLast = NULL;
    if (root->right) {
        right = formatBST2List(root->right, &rightLast);
    }

    if (left) {
        leftLast->next = mid;
        mid->next = right ? right : NULL;
        *last = right ? rightLast : mid;
        return left;
    } else {
        mid->next = right ? right : NULL;
        *last = right ? rightLast : mid;
        return mid;
    }
}

bool isValidBST(struct TreeNode* root){
    if (root == NULL) {
        return true; ////////
    }

    struct ListNode *last = NULL;
    struct ListNode *l = formatBST2List(root, &last);
    struct ListNode *cur = l;
    while (cur) {
        if (cur->next && cur->val >= cur->next->val) {
            return false;
        }
        cur = cur->next;
    }
    return true;
}
```