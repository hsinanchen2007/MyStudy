先保存头节点head2和头节点的下一个节点next
（head2的存在是为了保存next的前一个节点，方便删除重复节点）
如果head和next的值相等则删除next，并将next后移（head2不动，这时head2还是next的上一个节点）
如果不相等则将head2和next后移
直到next为空    
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* res = head;
        while (head) {
            ListNode* next = head->next;
            ListNode* head2 = head;
            while (next) {
                if (head->val == next->val) {
                    head2->next = next->next;
                } else {
                    head2 = head2->next;
                }
                next = next->next;
            }
            head =head->next;
        }
        return res;
    }
};