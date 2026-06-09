### 解题思路
解题思路：
1、首先遍历单链表，找到单链表尾节点，并得到单链表长度
2、将单项链表尾结点指向头节点，形成单向循环链表
3、对k有可能大于链表长度，对k除链表长度，取余数，为最少遍历次数。
4、k为所有节点向右移动的次数，即为尾结点向前遍历：（链表长度 - k） 次 为新的尾结点。
5、得到新的头结点、与新的尾结点。 断开首尾节点即可。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.c>
#define NULL 0
struct ListNode* rotateRight(struct ListNode* head, int k)
{
    struct ListNode *pTempNode = NULL;
    int iNodeNum = 1;
    int iWhileCount = 0;

    if ((NULL == head) || 
        (NULL == head->next))
    {
        return head;
    }

    pTempNode = head;
    while (NULL != pTempNode->next)
    {
        pTempNode = pTempNode->next;
        iNodeNum++;
    }

    if (0 == k % iNodeNum)
    {
        return head;
    }

    pTempNode->next= head;
    iWhileCount = iNodeNum - (k % iNodeNum);
    while (iWhileCount--)
    {
        pTempNode = pTempNode->next;
    }

    head = pTempNode->next;
    pTempNode->next = NULL;

    return head;
}
```