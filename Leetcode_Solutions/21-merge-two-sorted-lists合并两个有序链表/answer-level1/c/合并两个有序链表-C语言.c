### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/793a5f7a10c122a2b1711b1908e869e1e9a10784ee6a6c52dff73d66d9ef57bd-image.png)


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 方法一：迭代法 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* pstLnL1Head = NULL;
    struct ListNode* pstLnL2Head = NULL;
    struct ListNode* pstLnPre = NULL;
    if(NULL == l1)
    {
        return l2;
    }
    if(NULL == l2)
    {
        return l1;
    }
    pstLnL1Head = l1;
    pstLnL2Head = l2;

    /* 申请首节点。 */
    struct ListNode* pstLnPreHead = (struct ListNode*) malloc(sizeof(struct ListNode));
    pstLnPre = pstLnPreHead;

    /* 合并两个有序链表。 */
    while((NULL != pstLnL1Head) && (NULL != pstLnL2Head))
    {
        if(pstLnL1Head->val >= pstLnL2Head->val)
        {
            pstLnPre->next = pstLnL2Head;
            pstLnL2Head = pstLnL2Head->next;
        }
        else
        {
            pstLnPre->next = pstLnL1Head;
            pstLnL1Head = pstLnL1Head->next;
        }
        pstLnPre = pstLnPre->next;
    }

    /* 合并后的链表尾部节点指向剩余部分的有序链表。 */
    pstLnPre->next = (pstLnL1Head == NULL ? pstLnL2Head : pstLnL1Head);

    /* 找出合并排序好链表的头指针后，释放申请的首节点。 */
    pstLnPre = pstLnPreHead->next;
    free(pstLnPreHead);
    pstLnPreHead = NULL;

    return pstLnPre;

}
```