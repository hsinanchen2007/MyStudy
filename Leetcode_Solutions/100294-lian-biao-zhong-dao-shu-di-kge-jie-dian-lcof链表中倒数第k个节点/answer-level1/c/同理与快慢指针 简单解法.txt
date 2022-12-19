/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode *p=head,*q=head;
    while(p->next){
        if(k>1){
            p=p->next;  //让p领先q
            k-=1;
        }
        else{
            p=p->next;
            q=q->next;
        }
    }
    return q;
}