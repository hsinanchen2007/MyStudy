/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
struct ListNode *pa=l1;
struct ListNode *pb=l2;
struct ListNode *lc;
struct ListNode *pc;
pc=(struct ListNode*)malloc(sizeof(struct ListNode));
lc=pc;
while(pa&&pb){
    if(pa->val<=pb->val){
        pc->next=pa;pc=pa;pa=pa->next;
    }
    else{pc->next=pb;pc=pb;pb=pb->next;}
}
pc->next=pa?pa:pb;
return lc->next;
}
想问下大家这个它传入的两个链表有没头结点啊
