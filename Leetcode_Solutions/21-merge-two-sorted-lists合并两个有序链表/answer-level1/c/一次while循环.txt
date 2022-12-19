### 解题思路
又要入参判断。
双指针同时判断，判断完任意一个list之后，剩余的list直接添加到新的list最后即可。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (!l1 && !l2)
    {
        return NULL;
    }

    if (!l1)
        return l2;

    if (!l2)
        return l1;
    
    struct ListNode *resList;
    resList = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (NULL == resList)
    {
        return NULL;
    }

    struct ListNode *resListPtr;
    resListPtr = resList;

    while (l1 && l2)
    {
        if (l1->val > l2->val)
        {
            resListPtr->next = l2;
            l2 = l2->next;
        }
        else
        {
            resListPtr->next = l1;
            l1 = l1->next;
        }
        
        resListPtr = resListPtr->next;
        
    }

    if (l1)
    {
        resListPtr->next = l1;
    }

    if (l2)
    {
        resListPtr->next = l2;
    }

    return resList->next;
}
```