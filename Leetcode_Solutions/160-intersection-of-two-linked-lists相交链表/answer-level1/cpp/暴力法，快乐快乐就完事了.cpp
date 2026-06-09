
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL)return NULL;
        ListNode *p1=headA;
        ListNode *p2=headB;
        while(p1!=p2)
        {
            while(p2!=NULL)
            {
                p2=p2->next;
                if(p1==p2)
                return p1;
            }
            p2=headB;
            p1=p1->next;
            
        }
        if(p1==p2)
        return p1;
        else
        return NULL;
        
    }
};