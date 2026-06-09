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
        if(!head||!head->next) return true;
        ListNode *slow=head, *fast = head;
        while(fast->next&&fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *last=slow->next;
    /*    while(last->next)
        {
            ListNode *tmp=last->next;
            last->next=tmp->next;
            tmp->next=slow->next;
            slow->next = tmp;
        
        }
    */
        ListNode* pre = nullptr;
        ListNode* cur = last;
        while(cur){
            ListNode* temp = cur -> next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }

        while(pre){
            if (pre->val != head->val)  return false;
            pre = pre -> next;
            head = head ->next;
        }
        return true;
    }
};


```