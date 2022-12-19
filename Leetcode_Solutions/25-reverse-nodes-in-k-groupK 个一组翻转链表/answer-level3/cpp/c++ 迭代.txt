```
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next=head;
        auto lastTail=&dummy;
        auto prev=head;
        auto cur=prev->next;
        int i=1;
        auto curTail=head;
        while(1){
            if(i++%k==0){
                lastTail->next=prev;
                lastTail=curTail;
                if(len(cur)<k){
                    lastTail->next=cur;
                    return dummy.next;
                }
                lastTail->next=NULL;
                curTail=cur;
                prev=cur;
                cur=cur->next;
            }else{
                auto next=cur->next;
                cur->next=prev;
                prev=cur;
                cur=next;
            }
        }
        return dummy.next;
    }
    int len(ListNode* head){
        int len=0;
        while(head){
            ++len;
            head=head->next;
        }
        return len;
    }
};
```
