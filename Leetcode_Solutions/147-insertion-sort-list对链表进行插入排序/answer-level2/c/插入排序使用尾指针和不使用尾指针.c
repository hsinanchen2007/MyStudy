```
struct ListNode* insertionSortList(struct ListNode* head){
    if(head==NULL || head->next==NULL)return head;

    struct ListNode* dummyhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyhead->next = head;
    struct ListNode* p = head->next,*pre=head;

    while(p){
        struct ListNode* cur=dummyhead;
        while(cur->next && p->val>cur->next->val)
            cur = cur ->next;
        if(cur->next == p){
            pre = p;
            p = p->next;
        }
        else{
            pre->next = p->next;
            p->next = cur->next;
            cur->next = p;
            p = pre->next;
        }
    }
    return dummyhead->next;
}

//使用尾指针速度会明显提升，只要大于尾指针所指向的值就一定大于前面所有的值
struct ListNode* insertionSortList(struct ListNode* head) {
    if(!head||!head->next)
        return head;
    struct ListNode* pre = (struct ListNode*)malloc(sizeof(struct ListNode));
    pre -> next = head;

    struct ListNode* tail = head;
    struct ListNode* node = head->next; 

    while(node){
        if(node->val < tail->val){
            struct ListNode* cur = pre;
            while(cur->next && node->val >  cur->next->val){
                cur = cur->next;
            }
            tail->next = node->next;
            node->next = cur->next;
            cur->next =  node;
            node=tail->next;

        }else{
            tail = tail->next;
            node = tail->next;
        }
    }
    return pre->next;
}
```
使用尾指针的算法参考这篇
[https://leetcode-cn.com/problems/insertion-sort-list/solution/12ms-99ji-ben-de-cha-ru-pai-xu-by-tiyife/]()