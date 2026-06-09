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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummyLess(0);
        ListNode dummyGreat(0);
        auto less=&dummyLess;
        auto great=&dummyGreat;
        auto p=head;
        while(p){
            if(p->val<x){
                less->next=p;
                less=p;
            }else{
                great->next=p;
                great=p;
            }
            p=p->next;
        }
        less->next=dummyGreat.next;
        great->next=NULL;
        return dummyLess.next;
    }
};
```
