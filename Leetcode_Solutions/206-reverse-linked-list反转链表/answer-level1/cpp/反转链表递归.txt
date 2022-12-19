### 解题思路
************************************************
##常规递归思路，贴上代码:
```cpp
    class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* curr=head;
            ListNode* t;
            if(curr)
                if(curr->next!=NULL){
                    head = reverseList(curr->next);
                    curr->next=NULL;
                    t=head;
                    while(t->next)
                    t=t->next;
                    t->next=curr;
                }
            return head;
        }
    };
```