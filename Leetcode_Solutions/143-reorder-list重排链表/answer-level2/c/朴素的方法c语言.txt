```
struct ListNode* reverseList(struct ListNode* head){//辅助函数，将链表逆序
    struct ListNode* dummyhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyhead->next = NULL;
    struct ListNode* r;
    while(head){
        r = head->next;
        head->next = dummyhead->next;
        dummyhead->next = head;
        head = r;
    }
    return dummyhead->next;

}

void reorderList(struct ListNode* head){
    if(head==NULL || head->next==NULL)return head;
    struct ListNode* fast = head->next,*slow = head;
    while(fast && fast->next){                //快慢指针找中点
        slow= slow->next;
        fast = fast->next->next;
    }

    struct ListNode* righthead = slow->next,*r;
    slow->next = NULL;//断链

    //将右边链表逆序
    fast = reverseList(righthead);
    slow = head;

    //将逆序的链表插入左边链表
    while(fast){
        r = fast->next;
        fast->next = slow->next;
        slow->next = fast;
        slow = fast->next;
        fast = r;
    }

}
```
