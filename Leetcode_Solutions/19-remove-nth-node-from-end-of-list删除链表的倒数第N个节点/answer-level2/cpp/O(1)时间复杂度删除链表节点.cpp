```
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        int m = 0;
        while (p) {
            p = p->next;
            m++;
        }
        p = head;
        int pre = m - n;
        while (pre > 0 && p != NULL) {
            p = p->next;
            pre--;
        }
        if (p->next) {
            p->val = p->next->val;
            p->next = p->next->next;
        } else {
            // 要删除的是结尾元素
            //从头到尾遍历一次
            ListNode *q = new ListNode(0); 
            ListNode *dummy = q; 
            q->next = head;
            while (q && m-1 != 0) {
                q = q->next;
                m--;
            }
            q->next = NULL;
            head = dummy->next;
        }
        return head;
    }
};
```
