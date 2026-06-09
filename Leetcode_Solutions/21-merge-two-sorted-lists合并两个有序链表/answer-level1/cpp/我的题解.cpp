class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode newhead(0);
        ListNode* headptr = &newhead;
        while(l1 && l2){
            if(l1->val < l2->val){
                headptr->next = l1;
                l1 = l1->next;
            }
            else{
                headptr->next = l2;
                l2 = l2->next;
            }
            headptr = headptr->next;
        }
        if(l1){
            headptr->next = l1;

        }
        if(l2){
            headptr->next = l2;

        }
        return newhead.next;
    }
};