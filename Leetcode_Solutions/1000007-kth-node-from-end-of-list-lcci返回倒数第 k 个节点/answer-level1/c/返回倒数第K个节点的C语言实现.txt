### 解题思路
该题利用链表的反转来解决，思路如下:
* 入参检查
* 链表反转
* 遍历反转后的链表，并输出第k个节点的值

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* invertlist(struct ListNode *head)
{
    if(!head)
    {
        return;
    }

    struct ListNode *newHead = NULL;
    struct ListNode *tmp;
    while(head)
    {
        tmp = head->next;
        head->next = newHead;
        newHead = head;
        head = tmp;
    }
    return newHead;
}

int kthToLast(struct ListNode* head, int k)
{
    if(!head)
    {
        return 0;
    }

    struct ListNode *tmp = invertlist(head);

    while(k>1)
    {
        tmp = tmp->next;
        k--;
    }
    return tmp->val;
}
```