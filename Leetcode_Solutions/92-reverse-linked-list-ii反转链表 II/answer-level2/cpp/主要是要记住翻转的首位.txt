- class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* prehead = new ListNode(-1);
        if(head == NULL || head->next == NULL || m == n)
            return head;
        prehead->next = head;
        ListNode* pre = prehead;
        ListNode* s = head;
        ListNode* q = head;
        ListNode* p = head->next;
        ListNode* cur = p;
        int k = 1;
        while(k <= n)
        {
            if(k < m)
            {
                pre = pre->next;
                q = q->next;
                p = p->next;
                s = s->next;
                cur = cur->next;
            }
            else if(k >= m && k < n)
            {
                
                cur = p->next;
                p->next = s;
                s = p;
                p = cur;
            }
            else
            {
                q->next = p;
                pre->next = s;
            }
            k++;
        }
        return prehead->next;
    }
};