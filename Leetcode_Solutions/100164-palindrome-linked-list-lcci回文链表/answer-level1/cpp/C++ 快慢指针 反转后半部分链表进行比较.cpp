### 解题思路
此处撰写解题思路

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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
       if(head==nullptr||head->next==nullptr){
           return true;
       }
       ListNode*fast=head;
       ListNode*slow=head;
       ListNode*pre=NULL;
       while(fast&&fast->next){
           slow=slow->next;
           fast=fast->next->next;
       }
       while(slow){
           ListNode*tmp=slow->next;
           slow->next=pre;
           pre=slow;
           slow=tmp;
       }
       while(head&&pre){
           if(head->val!=pre->val){
               return false;
           }
           head=head->next;
           pre=pre->next;
       }
       return true;
    }
};
```