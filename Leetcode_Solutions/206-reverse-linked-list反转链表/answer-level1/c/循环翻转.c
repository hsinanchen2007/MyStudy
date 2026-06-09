### 解题思路
没有头结点，需要自己构造一个头结点。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL)
    {
        return NULL;
    }

    struct ListNode* pNewHead;
    struct ListNode* p;
    struct ListNode* tmp;
    pNewHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (pNewHead == NULL)
    {
        return NULL;
    }
    pNewHead->next = NULL;

    p = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (p == NULL)
    {
        return NULL;
    }
    p->next = head;

    int i = 0;
    while (p != NULL && p->next != NULL)
    {
        tmp = p->next->next;
        p->next->next = pNewHead->next;
        pNewHead->next = p->next;
        p->next = tmp;
    }

    return pNewHead->next;

}
```