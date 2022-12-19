
参考他人解题思路，使用了三个节点，把后边的节点依次放到前边来
    
```c
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode *prev = head;
    struct ListNode *cur = head->next;
    struct ListNode *temp = NULL;

    while (cur != NULL) {
        temp = cur->next;
        prev->next = temp;
        cur->next = head;
        head = cur;
        cur = temp;
    }

    return head;
}
```







