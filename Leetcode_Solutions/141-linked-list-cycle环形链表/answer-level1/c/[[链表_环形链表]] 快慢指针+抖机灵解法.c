标准快慢指针解法，快慢指针在环形跑道上必然相遇

```c
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow=head;
    struct ListNode *fast=head; 
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
	return false;
}
```

看到评论区有个抖机灵做法，让遍历过的结点指向同一个结点p
```c
bool hasCycle(struct ListNode *head) {
    struct ListNode *p=(struct ListNode*)malloc(sizeof(struct ListNode));
    p->next=NULL; 
    struct ListNode *q=head;
    while(head){
        if(head->next==p){
            return true;
        }
        q=head->next;
        head->next=p;
        head=q;
    }
	return false;
}
```