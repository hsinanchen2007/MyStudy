此方法重点在于求得环长度后的相等关系的计算，要用到数学知识，但又不能完全当做数学来做。
```
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * fast = head;
        ListNode * slow = head;

        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast==slow){
                ListNode * cur = head;
                while(cur!=slow){
                    cur=cur->next;
                    slow=slow->next;
                }
                return cur;
            }
        }

        return NULL;
    }
};
```
