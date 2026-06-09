第一步：求两个链表的长度len1,len2
第二步：如果len1>len2，则链表一往前走len1-len2路程；否则链表二往前走len2-len1的路程。
第三步：同时向前走，如果走到某步结点相等，则返回该节点；走完都没发现相等的结点，返回NULL

```
int getLen(struct ListNode* head){
    int len=0;
    while(head!=NULL){
        head=head->next;
        len++;
    }
    return len;
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int len1=getLen(headA);
    int len2=getLen(headB);
    if(len1==0||len2==0) return NULL;
    struct ListNode *p1=headA,*p2=headB;
    if(len1>len2){
        for(int i=0;i<len1-len2;i++){
            p1=p1->next;
        }
    }else{
        for(int i=0;i<len2-len1;i++){
            p2=p2->next;
        }
    }
    while(p1!=NULL&&p2!=NULL){
        if(p1==p2) return p1;
        else{
            p1=p1->next;
            p2=p2->next;
        }
    }
    return NULL;
}
```
