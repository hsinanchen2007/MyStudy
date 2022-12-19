```
struct ListNode* sortList(struct ListNode* head){
    if(head==NULL||head->next==NULL)return head;
    struct ListNode*p=head;
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    p=head;
    for(int i=1;i<len/2;i++){
        p=p->next;
    }    
    struct ListNode*fast=p->next;
    p->next=NULL;
    struct ListNode*left= sortList(head);
    struct ListNode*right= sortList(fast);
    struct ListNode*node=malloc(sizeof(*node));
    node->next=NULL;
    struct ListNode*n=node;
    while(left||right){
        if(left&&right){
            if(left->val>right->val){
                n->next=right;
                right=right->next;
            }else{
                n->next=left;
                left=left->next;
            }
        }else if(left){
            n->next=left;
            left=left->next;
        }else if(right){
            n->next=right;
            right=right->next ;
        }
        n=n->next;
    }       
    
    return node->next;
}
```
