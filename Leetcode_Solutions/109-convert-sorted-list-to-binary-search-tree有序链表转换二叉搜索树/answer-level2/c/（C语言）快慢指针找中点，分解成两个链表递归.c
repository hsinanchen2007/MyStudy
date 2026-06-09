### 解题思路
slow指向中点，pre指向slow的前一个结点。令pre->next=null，分解成两个链表head和slow->next。
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


struct TreeNode* sortedListToBST(struct ListNode* head){
    if(!head) return NULL;
    struct TreeNode *root=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct ListNode *fast=head;
    struct ListNode *slow=head;
    struct ListNode *pre=head;

    while(fast&&fast->next){
        pre=slow;
        slow=slow->next;
        fast=fast->next->next;
    }

    root->val=slow->val;

    if(pre==slow)
        root->left=NULL;
    else{
        pre->next=NULL;
        root->left=sortedListToBST(head);
    }

    root->right=sortedListToBST(slow->next);

    return root;
}
```