p->next 记得要赋空值！

```C
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){   
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode *p = NULL;
    struct ListNode *pre = head;
    int flag = 0; // 表示进位
    int sum = 0;  // 表示两数求和
    while(l1 != NULL && l2 != NULL) {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        sum = l1->val + l2->val + flag;
        if (sum < 10) {
            p->val = sum;
            flag = 0;
        } else {
            p->val = sum - 10;
            flag = 1;
        }
        pre->next = p;
        pre = p;
        l1 = l1->next;
        l2 = l2->next;
        p->next = NULL;
    }
    if (l2 != NULL) {
        l1 = l2;
    }
    while(l1 != NULL) {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        sum = l1->val + flag;
        if (sum < 10) {
            p->val = sum;
            flag = 0;
        } else {
            p->val = sum - 10;
            flag = 1;
        }
        p->next = NULL;
        pre->next = p;
        pre = pre->next;
        l1 = l1->next;
    }
    if (flag != 0) {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val = flag;
        p->next = NULL;
        pre->next = p;
    }
    return head->next;
}
```