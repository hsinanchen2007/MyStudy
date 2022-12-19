### 解题思路
中序遍历的序列是sorted的。
利用快慢指针找到中间节点，左右分别构造。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct ListNode* FindMidNode(struct ListNode *head, struct ListNode **pprev)
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    struct ListNode *prev = NULL;
    while (fast!=NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    *pprev = prev;
    return slow;
}

struct TreeNode* sortedListToBST(struct ListNode* head)
{
    if (head == NULL) {
        return NULL;
    }
    struct ListNode *left;
    struct ListNode *midNode;
    struct ListNode *right;
    midNode = FindMidNode(head, &left);
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (root == NULL) {
        return NULL;
    }
    root->left = NULL;
    root->right = NULL;

    root->val = midNode->val;
    if (left != NULL) {
        left->next = NULL;
        root->left = sortedListToBST(head);
    }
    if (midNode->next != NULL) {
        root->right = sortedListToBST(midNode->next);
    }
    return root;
}
```