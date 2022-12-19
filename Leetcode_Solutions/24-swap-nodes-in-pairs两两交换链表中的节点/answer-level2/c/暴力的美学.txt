![无标题.png](https://pic.leetcode-cn.com/c531b40f9a561b18a1ed51102b8abbf31e407e6f92dbeede279faa21bf1e7160-%E6%97%A0%E6%A0%87%E9%A2%98.png)

本题主要采用了三个核心指针，分别用来记录用于交换的左侧结点（auxLeft）和右侧结点（auxRight），以及用来保证链表顺序性的父结点（auxParent）。
算法很粗暴，但效率很高。

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode *newList;
    struct ListNode *auxLeft, *auxRight, *auxParent;   //辅助用
    
    if(head == NULL)
        return NULL;

    newList = head;
    auxLeft = head;
    auxRight = auxLeft->next;
    if(auxRight != NULL)
    {
        auxLeft->next = auxRight->next;
        auxRight->next = auxLeft;
        newList = auxRight;
        auxParent = auxLeft;

        auxLeft = auxLeft->next;
        if(auxLeft == NULL)
            return newList;
        else
            auxRight = auxLeft->next;
    }

    while(auxRight != NULL)
    {
        auxLeft->next = auxRight->next;
        auxRight->next = auxLeft;
        auxParent->next = auxRight;
        auxParent = auxLeft;

        auxLeft = auxLeft->next;
        if(auxLeft == NULL)
            return newList;
        else
            auxRight = auxLeft->next;
    }

    return newList;
}
```
