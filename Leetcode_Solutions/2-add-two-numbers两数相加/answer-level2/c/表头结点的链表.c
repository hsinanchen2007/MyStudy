### 解题思路
长度相同：
1 + 1 = 2;
9 + 9 =18;
长度不相同：
99 + 9 = 188;
19 + 9 = 28;

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void insert(const struct ListNode* head, const int val)
{
    struct ListNode* q = (struct ListNode*)malloc(sizeof(struct ListNode));
    q->val = val;
    q->next = NULL;
    struct ListNode* p = head;
    while (p->next) {
        p = p->next;
    }
    p->next = q;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int jinwei = 0;
    int num = 0;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    while (l1 || l2) {
        if(l1 == NULL) num = l2->val + jinwei;
        if(l2 == NULL) num = l1->val + jinwei;
        if(l1 && l2) num = l1->val + l2->val + jinwei;

        if (num > 9) {
            num = num % 10;
            jinwei = 1;
        }
        else jinwei = 0;
        insert(head, num);
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    if(jinwei == 1) insert(head, jinwei);
    return head->next;
}
```