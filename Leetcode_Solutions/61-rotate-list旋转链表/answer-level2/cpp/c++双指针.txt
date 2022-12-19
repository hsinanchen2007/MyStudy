注意考虑边界情况 其实就是第k个指针的问题
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next or k ==0) return head;
        ListNode *f = head;
        ListNode *now = head;
        ListNode *more = head;
        ListNode *newhead = head;
        int i;
        for(i=0;i<k and more->next != NULL;i++){
            more = more->next;
        }
        if(i!=k){
            i++;
            k = k%i;
            if( k== 0) return head;
            more = head;
            for(i=0;i<k and more->next != NULL;i++){
               more = more->next;
            }
        }
       while(more->next != NULL){
           more = more->next;
           now = now->next;
       } 
       newhead = now->next;
       now->next = more->next;
       more->next = f;
       return newhead;
    }
};
```
