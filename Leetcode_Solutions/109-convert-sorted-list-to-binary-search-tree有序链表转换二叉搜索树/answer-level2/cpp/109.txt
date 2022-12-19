### 解题思路
第一种：通过双指针slow,fast定位二分点，然后递归
第二种：参考LeetCode官方的解释，通过移入数组，然后采用mid=(left+right)/2的方式进行运算，用空间换取时间，挺不错的。

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return NULL;
        } 
        else if(head->next==NULL){
            return new TreeNode(head->val);
        }
        else{
            ListNode* head_ptr=new ListNode(-1);
            head_ptr->next=head;
            ListNode* tail=head_ptr,*slow=head,*fast=head;
            
            while(fast!=NULL && fast->next!=NULL){
                fast=fast->next->next;
                slow=slow->next;
                tail=tail->next;
            }
            
            tail->next=NULL;
            TreeNode* tmp=new TreeNode(slow->val);
            tmp->left=sortedListToBST(head);
            tmp->right=sortedListToBST(slow->next);
            return tmp;
        }
    }
};
```