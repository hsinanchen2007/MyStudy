利用双指针法，一次遍历即可完成题目要求。
```c
struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode*slow_p=head,*p=head;
    while(k--) p=p->next;
    while(p!=0){
        slow_p=slow_p->next;
        p=p->next;
    }
    return slow_p;
}
```