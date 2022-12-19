注意点：
1. 链表归并不用申请新内存，直接指针来回指
2. 快慢指针找来链表中点*前一个*，代码说话：
    
```c
struct ListNode *slow = head, *fast = head->next; //上来就多走一步
while(fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}
```
然后就分成了两部分
```c
fast = slow->next;
slow->next = NULL; //*************关键忘了，前半部分末尾一定别忘指空
```

完整代码
```c
struct ListNode *merge(struct ListNode *l1, struct ListNode *l2) {
   struct ListNode head;
   struct ListNode *p = &(head);
   p->next = NULL;
   while(l1 && l2) {
       if(l1->val <= l2->val) {
           p->next = l1;
           l1 = l1->next;
       } else {
           p->next = l2;
           l2 = l2->next;
        }
        p = p->next;
    }
    if(l1) p->next = l1;
    if(l2) p->next = l2;
    return head.next;
}


struct ListNode* sortList(struct ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    struct ListNode *slow = head, *fast = head->next; //上来就多走一步
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL; //*************关键忘了
    struct ListNode *l = sortList(head), *r = sortList(fast);
    return merge(l, r);
}
```
