### 解题思路
先对齐，再偏移相同的值即可。1、比较两个链表串的长度，长度较长的就把指针偏移到相同的位置，2、两个指针同步前进，直到两个指针指向同一个地址，也就找到了结果。时间复杂度O(N)，空间复杂度O(1)。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getListLength (struct ListNode *pList)
{
    int length = 0;
    while(pList)
    {
        length ++;
        pList = pList->next;
    }
    return length;
}

struct ListNode *moveToEqualLength(int length, struct ListNode *pList)
{
    while (pList && length != 0)
    {
        pList = pList->next;
        length --;
    }
    return pList;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

    int lengthListA = getListLength(headA);
    int lengthListB = getListLength(headB);

    if (lengthListA > lengthListB)
    {
        headA = moveToEqualLength((lengthListA - lengthListB), headA);
    }
    else
    {
        headB = moveToEqualLength((lengthListB - lengthListA), headB);
    }

    while (headB && headA)
    {
        if (headA == headB)
        {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }

    return NULL;
    
}
```