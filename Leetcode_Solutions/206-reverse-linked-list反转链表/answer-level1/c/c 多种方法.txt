```c
// 头插
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *old = NULL;
    while (head) {
        struct ListNode *new = (struct ListNode *)malloc(sizeof(ctruct ListNode));
        new->val = head->val;
        new->next = old;
        old = new;
        head = head->next;
    }
    return old;
}

// 迭代 把头指针移动到最后
struct ListNode* reverseList1(struct ListNode* head){
    struct ListNode *prev = head;
    while (head && head->next) {
        struct ListNode *temp = head->next;
        head->next = temp->next;
        temp->next = prev;
        prev = temp;
    }
    return prev;
}

// 双指针迭代
struct ListNode* reverseList2(struct ListNode* head){
    struct ListNode *prev = NULL;
    struct ListNode *cur = head;
    while (cur) {
        struct ListNode *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}

// 递归
struct ListNode* reverseList3(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *newHead = reverseList2(head->next);// 为最后一个节点
    // head->next 指向 head
    head->next->next = head;
    head->next = NULL;
    // 不断返回最后一个节点
    return newHead;
}
```
