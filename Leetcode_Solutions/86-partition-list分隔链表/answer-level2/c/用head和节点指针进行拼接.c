### 解题思路
需要申请临时头结点，然后将小于目标值x的数和大于等于目标值的数分别建立链表（less和more），并申请两个指针分别指向这两个链表，这两个新申请的指针始终指向最后一个节点（lessPtr，morePtr）。
最后，将两个新建立的链表链接起来，即less的链表尾指向more链表的head->next，并且morePtr->next=NULL。
最后返回less->next。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode* lessHead;
    struct ListNode* lessPtr;
    struct ListNode* moreHead;
    struct ListNode* morePtr;

    lessHead = (struct ListNode*)malloc (sizeof(struct ListNode));
    if (lessHead == NULL)
        return NULL;
    lessHead->next = NULL;
    lessPtr = lessHead;

    moreHead = (struct ListNode*)malloc (sizeof(struct ListNode));
    if (moreHead == NULL)
        return NULL;
    moreHead->next = NULL;
    morePtr = moreHead;

    while (head)
    {
        if (head->val < x)
        {
            lessPtr->next = head;
            lessPtr = head;
        }
        else
        {
            morePtr->next = head;
            morePtr = head;
        }

        head = head->next;
    }

    lessPtr->next = moreHead->next;
    morePtr->next = NULL;

    return lessHead->next;

}
```