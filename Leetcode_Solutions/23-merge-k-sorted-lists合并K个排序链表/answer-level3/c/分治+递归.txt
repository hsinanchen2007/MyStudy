### 解题思路
结合两个链表合并的题目，用分治+递归的方式，降低时间复杂度。
另外，第一部分的mergeTwoList也可以使用递归方式进行改造，减少代码的冗余。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoList(struct ListNode* l1, struct ListNode* l2)
{
    if (!l1 && !l2)
        return NULL;
    
    if (!l1)
        return l2;

    if (!l2)
        return l1;

    struct ListNode *restList;
    struct ListNode *restListPtr;
    restList = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (!restList)
    {
        return NULL;
    }
    restList->next = NULL;
    restListPtr = restList;

    while (l1 && l2)
    {
        if (l1->val > l2->val)
        {
            restListPtr->next = l2;
            l2 = l2->next;
        }
        else
        {
            restListPtr->next = l1;
            l1 = l1->next;
        }
        restListPtr = restListPtr->next;
    }

    if (l1)
    {
        restListPtr->next = l1;
    }
    if (l2)
    {
        restListPtr->next = l2;
    }

    return restList->next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (listsSize == 0)
    {
        return NULL;
    }

    if (listsSize == 1)
    {
        return lists[0];
    }

    if (listsSize == 2)
    {
        return mergeTwoList(lists[0], lists[1]);
    }

    int mid = listsSize / 2; ////分治
    struct ListNode *listsA[mid];
    struct ListNode *listsB[listsSize - mid];

    for (int i = 0; i < mid; i ++)
    {
        listsA[i] = lists[i];
    }
    for (int i = mid; i < listsSize; i ++)
    {
        listsB[i-mid] = lists[i];
    }

    struct ListNode *l1;
    struct ListNode *l2;

    l1 = mergeKLists(listsA, mid);
    l2 = mergeKLists(listsB, listsSize - mid);

    return mergeTwoList(l1, l2);


    return NULL;
}
```