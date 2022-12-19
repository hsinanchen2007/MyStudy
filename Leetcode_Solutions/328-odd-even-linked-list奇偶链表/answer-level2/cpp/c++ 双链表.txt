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
    ListNode* oddEvenList(ListNode* head) {
        ListNode dummyOdd(0);
        ListNode dummyEven(0);
        auto odd=&dummyOdd;
        auto even=&dummyEven;
        auto p=head;
        int i=1;
        while(p){
            if(i++%2==1){
                odd->next=p;
                odd=p;
            }else{
                even->next=p;
                even=p;
            }
            p=p->next;
        }
        odd->next=dummyEven.next;
        even->next=NULL;
        return dummyOdd.next;
    }
};
```
