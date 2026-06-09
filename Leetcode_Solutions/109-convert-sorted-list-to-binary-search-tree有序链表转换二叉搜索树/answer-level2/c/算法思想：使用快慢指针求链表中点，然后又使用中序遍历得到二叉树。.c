### 解题思路
此处撰写解题思路

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

struct TreeNode* helper(struct ListNode* head,struct ListNode* tail){
    if(head==tail) return NULL;

//      初始化快慢指针
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast!=tail && fast->next!=tail){
        slow = slow->next;
        fast = fast->next->next;
    }   

//  慢指针指向中点
    struct TreeNode* root =
     (struct TreeNode*)malloc(sizeof(struct TreeNode));   
     root->val = slow->val;
     root->left = helper(head,slow);
     root->right = helper(slow->next,tail);
     return  root;
}
struct TreeNode* sortedListToBST(struct ListNode* head){
    if(head==NULL)  return NULL;
    return helper(head,NULL);
}
```