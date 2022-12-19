```
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* head_2 = new ListNode(0);
        head_2 -> next = head;
        head = head_2;
        ListNode* tail = head;
        int cnt = 1;
        
        while(tail != nullptr){
            ListNode* tp = tail -> next;
            if(cnt == m){
                ListNode* tail_2 = tp;
                while(cnt <= n){
                    ListNode* tp_2 = tp -> next;
                    tp -> next = tail -> next;
                    tail -> next = tp;
                    tp = tp_2;
                    cnt++;
                }
                tail_2 -> next = tp;
                break;
            }else{
                tail = tail -> next;    
                cnt++;
            }
        }
        
        return head -> next;
    }
};
```
