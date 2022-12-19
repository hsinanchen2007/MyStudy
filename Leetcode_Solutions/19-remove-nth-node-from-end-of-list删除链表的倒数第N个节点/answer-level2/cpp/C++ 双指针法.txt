注意考虑特殊情况，指针q比p先走n步！
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* q = head;
        int cnt = 0;
        while(q!=NULL)
        {
            if(cnt+1 == n && q->next==NULL) return head->next;
            if(cnt <= n) q = q->next;
            else{
                p = p->next;
                q = q->next;
            }
            cnt++;
        }
        if(head->next!=NULL && p->next!=NULL) p->next = p->next->next;
        else if(n==1) return NULL;
        return head;
    }
};
```
