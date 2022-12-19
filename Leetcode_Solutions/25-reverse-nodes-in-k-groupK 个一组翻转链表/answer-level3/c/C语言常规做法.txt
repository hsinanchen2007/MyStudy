提交后发现，题目要求使用常数空间实现，故递归不满足题目要求。但由于解题思路相近，将递归代码贴出，改日再用迭代方法重做。
```c
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode* tmp=head,*keep;
    short counter=k;
    while(counter--){
        if(tmp==0) return head;
        tmp=tmp->next;
    }
    counter=k;
    tmp=head;
    while(--counter){
        keep=tmp->next;
        tmp->next=keep->next;
        keep->next=head;
        head=keep;
    }
    tmp->next=reverseKGroup(tmp->next,k);
    return head;
}
```