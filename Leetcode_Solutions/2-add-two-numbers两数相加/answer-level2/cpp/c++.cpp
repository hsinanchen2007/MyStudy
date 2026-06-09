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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy=new ListNode(-1);
        int carry=0;
        auto p=dummy;
        while(l1||l2){
            int a=l1?l1->val:0;
            int b=l2?l2->val:0;
            p->next=new ListNode((a+b+carry)%10);
            p=p->next;
            carry=(a+b+carry)/10;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        if(carry>0)p->next=new ListNode(carry);
        return dummy->next;
    }
};
```
