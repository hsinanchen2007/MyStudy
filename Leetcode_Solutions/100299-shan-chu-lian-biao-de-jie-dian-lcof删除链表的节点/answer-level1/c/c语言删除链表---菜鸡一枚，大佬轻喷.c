/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val){
       struct ListNode* q;
       q=head;
       if(head==NULL) return head;
       if(head->val==val) {head=head->next;return head;}
       while(q->next->val!=val) q=q->next;
       q->next=q->next->next;
       return head;
}