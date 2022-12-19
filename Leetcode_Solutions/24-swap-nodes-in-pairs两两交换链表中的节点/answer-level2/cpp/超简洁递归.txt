简单递归
class Solution {
public:
    ListNode* swapPairs(ListNode* head){
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* l1 = head->next;
        head->next = swapPairs(head->next->next);
        l1->next = head;
        return l1;
    }
};