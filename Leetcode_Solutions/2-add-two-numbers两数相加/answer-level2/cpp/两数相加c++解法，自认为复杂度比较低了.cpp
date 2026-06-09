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
		ListNode* head = new ListNode(0);//头结点
		ListNode* L = head;//移动指针
        int val1=0,val2=0,c=0;
        while(l1!=NULL||l2!=NULL)
        {
            if(l1==NULL) val1=0;
            else val1=l1->val;
            if(l2==NULL) val2=0;
            else val2=l2->val;
            ListNode *p=new ListNode((val1+val2+c)%10);
            if((val1+val2+c)>9) c=1;
            else c=0;
            L->next=p;
            L=p;
            if(l1!=NULL)l1=l1->next;
            if(l2!=NULL)l2=l2->next;
        }
        if(c)
        {
            ListNode *p=new ListNode(1);
            L->next=p;
        }
        return head->next;

    }
    
};