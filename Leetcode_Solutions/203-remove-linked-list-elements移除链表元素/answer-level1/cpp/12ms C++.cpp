class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ret = new ListNode(0);
        ret -> next = head;
        ListNode* elem = ret;
        while(elem->next  != nullptr)
        {
            ListNode* temp = elem->next;
            if(temp->val == val) elem->next = temp->next;
            else elem = elem->next;
        }
        return ret->next;
    }
};