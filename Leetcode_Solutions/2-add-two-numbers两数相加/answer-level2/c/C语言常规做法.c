逢十进一，注意处理特殊情况，另需要特别注意空指针。
该方法时间复杂度O(N)，空间复杂度O(1)。
```c
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    short from_lower=0;
    struct ListNode* head=l1;
    while(l1->next!=0&&l2->next!=0){
        l1->val=l1->val+l2->val+from_lower;
        if(l1->val>9){
            l1->val=l1->val-10;
            from_lower=1;
        }
        else from_lower=0;
        l1=l1->next;
        l2=l2->next;
    }
    //以下if语句保证l1是较长的那条链表。
    if(l1->next==0&&l2->next!=0) l1->next=l2->next;
    from_lower=from_lower+l2->val;
    while(l1!=0){
        l1->val=l1->val+from_lower;
        if(l1->val>9){
            l1->val=l1->val-10;
            from_lower=1;
        }
        else from_lower=0;
        l1=l1->next;
    }
    if(from_lower){
        struct ListNode* node=malloc(sizeof(struct ListNode));
        node->val=1;
        node->next=0;
        l1=head;
        while(l1->next!=0) l1=l1->next;
        l1->next=node;
    }
    return head;
}
```