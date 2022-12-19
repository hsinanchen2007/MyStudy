### 解题思路
具体看注释

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 暴力破解时间复杂度过高O(MN)
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

    struct ListNode *ptrA = NULL,*ptrB = NULL;

    if(headA == NULL || headB == NULL)
    {
        return NULL;
    }

    ptrA = headA;
    ptrB = headB;

    while(ptrA != NULL)
    {
        while(ptrB != NULL)
        {
            if(ptrA == ptrB)
            {
                return ptrA;
            }
            ptrB = ptrB->next;
        }
        // 指针指回头
        ptrB = headB;
        ptrA = ptrA->next;
    }
    return NULL;
}
// 双指针 （参考）
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p_a = headA;
    struct ListNode *p_b = headB;
    // 为空
    if(headA == NULL || headB == NULL)
    {
        return NULL;
    }
    // 循环
    while (1)
    {
        // 判断是否相等
        if (p_a == p_b)
        {
            return p_a;
        }
        // 不相等且不为空 后移
        if (p_a)
         {
             p_a = p_a->next;
         }
        // 为空
         else
         {
             p_a = headB;
         }
         if (p_b)
         {
            p_b = p_b->next;
         }
         else
         {
             p_b = headA;
         }
       
    }
    return NULL;
}

```