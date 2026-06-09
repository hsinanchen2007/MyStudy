### 解题思路
纯C

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
static struct TreeNode* dfs(struct ListNode* head, struct ListNode* tail)
{   
    if (head == tail)
    {
        return NULL;
    }

    // 找中点
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (fast != tail && fast->next != tail)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // 创建树
    struct TreeNode* pNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    pNode->val = slow->val;
    pNode->left = dfs(head, slow); // 左闭右开
    pNode->right = dfs(slow->next, tail);

    return pNode;
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    if (NULL == head)
    {
        return NULL;
    }

    return dfs(head, NULL);
}
```