- 方法一
此方法时间复杂度O(N)，空间复杂度O(1)。
```c
struct ListNode* reverseList(struct ListNode* head){
    if(head==0) return 0;
    struct ListNode*tmp,*header=head;
    while(head->next!=0){
        tmp=head->next;
        head->next=tmp->next;
        tmp->next=header;
        header=tmp;
    }
    return header;
}
```
- 方法二
此方法时间复杂度O(N)，空间复杂度O(N)。
```c
struct ListNode* reverseList(struct ListNode* head){
    if(head==0) return head;
    short length=0,i;
    struct ListNode* tmp=head;
    while(tmp!=0){
        length++;
        tmp=tmp->next;
    }
    tmp=head;
    short keep[length];
    for(i=0;i<length;i++){
        keep[i]=tmp->val;
        tmp=tmp->next;
    }
    tmp=head;
    for(i=length-1;i>=0;i--){
        tmp->val=keep[i];
        tmp=tmp->next;
    }
    return head;
}
```