class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        ListNode*p = head;
        ListNode*q = head;
        int len = 1;
        while(p->next)
        {
            p = p->next;
            len++;
        }
        int t = len - k % len;
        for(int i = 1;i < t;i++)
        {
            q = q->next;
        }
        p->next = head;
        head = q->next;
        q->next = NULL;
        return head;
    }
};