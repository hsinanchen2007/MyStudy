将要交换的两个节点视为整体的话，维护一个该节点的前驱和后继。
0ms
```
struct ListNode* swapPairs(struct ListNode* head){
    if (!head || !head->next) {
        return head;
    }
    struct ListNode *dummyhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyhead->next = head;
    struct ListNode *curnextswap = NULL,*curhead = NULL,*temp = NULL;
    curhead = dummyhead;
    
    curnextswap = (curhead->next->next->next)?curhead->next->next->next:NULL;    
    head->next->next = head;
    curhead->next = head->next;
    head->next = curnextswap;
    curhead = head;
    
    while (curnextswap && curnextswap->next) {
        curnextswap = (curnextswap->next->next)?curnextswap->next->next:NULL;    
        curhead->next->next->next = curhead->next;
        curhead->next = curhead->next->next;
        curhead->next->next->next = curnextswap;
        curhead = curhead->next->next;
    }
    return dummyhead->next;
    
}
```
4ms
```

struct ListNode* swapPairs(struct ListNode* head){
    if (!head || !head->next) {
        return head;
    }
    struct ListNode *dummyhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyhead->next = head;
    struct ListNode *curnextswap = NULL,*curhead = NULL,*temp = NULL;
    curhead = dummyhead;
    curnextswap = head;
    <!-- curnextswap = (curhead->next->next->next)?curhead->next->next->next:NULL;    
    head->next->next = head;
    curhead->next = head->next;
    head->next = curnextswap;
    curhead = head; -->
    
    while (curnextswap && curnextswap->next) {
        curnextswap = (curnextswap->next->next)?curnextswap->next->next:NULL;    
        curhead->next->next->next = curhead->next;
        curhead->next = curhead->next->next;
        curhead->next->next->next = curnextswap;
        curhead = curhead->next->next;
    }
    return dummyhead->next;
    
}
```
