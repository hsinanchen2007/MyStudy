先将链表分成两半（注意处理链表长度为奇数的情况），将其中一个链表反转，再逐个比较两链表的val值。
```c
bool isPalindrome(struct ListNode* head){
    if(head==0||head->next==0) return 1;
    struct ListNode* slow_p=head,* p=head;
    
    //找到链表的中间节点。
    while(p->next!=0&&p->next->next!=0){
        slow_p=slow_p->next;
        p=p->next->next;
    }
    
    //将链表分成两半。
    struct ListNode* head_=slow_p->next;
    slow_p->next=0;
    
    //将第二个链表反转。
    p=head_;
    while(p->next!=0){
        slow_p=head_;
        head_=p->next;
        p->next=p->next->next;
        head_->next=slow_p;
    }
    
    //按顺序比较两链表val值。
    while(head_!=0){
        if(head->val!=head_->val) return 0;
        head=head->next;
        head_=head_->next;
    }
    return 1;
}
```
以下代码是第一次提交通过的代码，当链表长度为奇数时，复制了一个节点使断开后两链表长度相等，实际上不需要这么做。
```c
bool isPalindrome(struct ListNode* head){
    if(head==0) return 1;
    struct ListNode* slow_p=head,* p=head;
    
    //找到链表的中间节点。
    while(p->next!=0&&p->next->next!=0){
        slow_p=slow_p->next;
        p=p->next->next;
    }
    
    //将链表分成两半。其中if语句处理链表长度为奇数的情况。
    struct ListNode* head_=slow_p->next;
    if(p->next==0){
        head_=malloc(sizeof(struct ListNode));
        head_->val=slow_p->val;
        head_->next=slow_p->next;
    }
    slow_p->next=0;
    
    //将第二个链表反转。
    p=head_;
    while(p->next!=0){
        slow_p=head_;
        head_=p->next;
        p->next=p->next->next;
        head_->next=slow_p;
    }
    
    //按顺序比较两链表val值。
    while(head!=0){
        if(head->val!=head_->val) return 0;
        head=head->next;
        head_=head_->next;
    }
    return 1;
}
```