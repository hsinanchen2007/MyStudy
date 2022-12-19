### 解题思路
循环递归
1，编写两个链表合并递归算法
2，循环递归得到最终合并链表
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoList(struct ListNode* l1, struct ListNode* l2){
    //1，递归结束条件
    if (NULL == l1)
    {
        return l2;
    }
    if (NULL == l2)
    {
        return l1;
    }

    //2，递归条件
    if (l1->val <= l2->val)
    {
        l1->next = mergeTwoList(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoList(l1, l2->next);
        return l2;
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int     i   = 0;

    struct ListNode* pHeadNode = NULL;

    if ((NULL == lists) || (0 == listsSize))
    {
        return NULL;
    }

    pHeadNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    pHeadNode->next = lists[0];

    for (i = 1; i < listsSize; i++)
    {
        pHeadNode->next = mergeTwoList(pHeadNode->next, lists[i]);
    }
    
    return pHeadNode->next;
}
```