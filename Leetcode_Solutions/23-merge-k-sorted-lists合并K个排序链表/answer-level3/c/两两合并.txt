官方题解"分治法" 的C语言实现

```C
struct ListNode *merge2Lists(struct ListNode *list1, struct ListNode *list2, struct ListNode *head)
{
    head->next = list1;
    struct ListNode *pre = head;
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            list1 = list1->next;
        } else {
            pre->next = list2;
            list2 = list2->next;
            pre->next->next = list1;
        }
        pre = pre->next;
    }
    pre->next = (list1 == NULL) ? list2 : list1;
    return head->next;
}


struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
    if (listsSize == 0) {
        return NULL;
    }
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    while (listsSize > 1) {
        for (int i = 0; i < listsSize; i += 2) {
            if (i + 1 == listsSize) {
                lists[i / 2] = lists[i];
            } else {
                lists[i / 2] = merge2Lists(lists[i], lists[i + 1], head);
            }
        }
        listsSize = listsSize / 2 + listsSize % 2;
    }
    free(head);
    return lists[0];
}
```