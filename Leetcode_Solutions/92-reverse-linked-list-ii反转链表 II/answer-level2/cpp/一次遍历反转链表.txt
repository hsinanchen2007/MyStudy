```c++
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* phead = head;
        if(!phead) return NULL;
        ListNode* forward = head; //记录反转开始节点前面的节点（m == 1则没有）
        ListNode* pre = NULL; //记录反转过程中的前继节点，m == 1 为forward的后继节点，否则为最终的头结点
        ListNode* back = NULL;//记录反转开始的节点，与整体反转后后面的节点衔接
        for (int i = 1; head; ++i) {
            if (i < m) {
                forward = head;
                head = head->next;
            } else if (i == m) {
                back = pre = head;
                head = head->next;
            } else if (i > m && i <= n) {
                ListNode* cur = head;
                head = head->next;
                cur->next = pre;
                pre = cur;
            } else break;
        }
        if (m != 1) {
            forward->next = pre;
            back->next = head;
            return phead;
        }
        else {
            back->next = head;
            return pre;
        } 
    }
};