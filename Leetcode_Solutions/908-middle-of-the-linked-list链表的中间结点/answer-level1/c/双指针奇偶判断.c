双指针奇偶判断
```
struct ListNode* middleNode(struct ListNode* head)
{
    if (head == NULL) {
        return NULL;
    }
    int count = 0;
    struct ListNode *mid = head;
    while (head->next != NULL) {
        head = head->next;
        count++;
        if (count % 2 == 1) {
            mid = mid->next;
        }
    }
    return mid;
}
```
