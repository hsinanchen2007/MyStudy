```
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==0 || head->next==0) return head;
        
        int len = 1;
        ListNode *tail = head;
        while(tail->next){
            ++len;
            tail = tail->next;
        }
        tail->next = head;

        if(k%=len){
            for(int i=0; i<len-k; ++i) tail = tail->next;
        }
        ListNode *res = tail->next;
        tail->next = 0;
        return res;
    }
};
```
