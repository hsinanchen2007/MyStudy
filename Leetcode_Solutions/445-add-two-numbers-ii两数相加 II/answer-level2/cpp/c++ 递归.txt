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
    int carry=0;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=0;
        auto p=l1;
        while(p){
            p=p->next;
            ++len1;
        }
        int len2=0;
        p=l2;
        while(p){
            p=p->next;
            ++len2;
        }
        p=add(l1,l2,len1,len2);
        if(carry>0){
            auto tmp=new ListNode(carry);
            tmp->next=p;
            p=tmp;
        }
        return p;
    }
    ListNode* add(ListNode* l1, ListNode* l2, int len1,int len2){
        if(len1>len2){
            auto res = new ListNode(0);
            res->next = add(l1->next,l2,len1-1,len2);
            res->val = (l1->val+carry)%10;
            carry = (l1->val+carry)/10;
            return res;
        } else if (len1<len2){
            auto res = new ListNode(0);
            res->next = add(l1,l2->next,len1,len2-1);
            res->val = (l2->val+carry)%10;
            carry = (l2->val+carry)/10;
            return res;
        } else {
            if(l1==NULL)return NULL;
            auto res = new ListNode(0);
            res->next = add(l1->next,l2->next,len1-1,len2-1);
            res->val = (l1->val+l2->val+carry)%10;
            carry = (l1->val+l2->val+carry)/10;
            return res;
        }
    }
};
```
