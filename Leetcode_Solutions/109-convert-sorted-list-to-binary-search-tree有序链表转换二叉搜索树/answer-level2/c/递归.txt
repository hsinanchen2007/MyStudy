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


struct TreeNode* sortedListToBST(struct ListNode* head){
    if(head==NULL) return NULL;
    struct TreeNode *root;
    root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    int i=0;
    struct ListNode *p=head,*pre;
    while(p){
        i++;
        p=p->next;
    }
    i=i/2;
    if(i==0){
        root->val=head->val;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    p=head;
    while(i--){
        pre=p;
        p=p->next;
    }
    root->val=p->val;
    p=p->next;
    pre->next=NULL;
    root->left=sortedListToBST(head);
    root->right=sortedListToBST(p);
    return root;
}
```