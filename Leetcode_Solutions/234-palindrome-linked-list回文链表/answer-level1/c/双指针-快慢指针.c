### 解题思路
使用快慢指针定位到最中间节点，反转后半部分节点，然后开始头尾比较。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
      if(!head||!head->next) return 1;
      struct ListNode *slow=head,*fast=head,*pre=NULL;
      while(fast&&fast->next){
          slow=slow->next;
          fast=fast->next->next;
      }
      while(slow){
          struct ListNode *nex=slow->next;
          slow->next=pre;
          pre=slow;
          slow=nex;
      }
      while(pre&&head){
          if(pre->val!=head->val) return false;
          pre=pre->next;
          head=head->next;
      }
      return true;
}
```