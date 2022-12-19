### 解题思路
1、思路
两个dummyHead建立两个链表，一个链表放小于x的节点，一个链表放大于等于x的节点，然后拼接两段链表。注意尾指针一定要赋值为空。

2、运行结果
![image.png](https://pic.leetcode-cn.com/8573227633c6580b80d9ad1ed9280e5956c41665efc82d36ae170a471cda659e-image.png)

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
    struct ListNode *pstLnPre1 = NULL;
    struct ListNode *pstLnPre2 = NULL;
    struct ListNode *pstLnCur = NULL;
    struct ListNode stLnHead1 = {0};
    struct ListNode stLnHead2 = {0};
    if(NULL == head)
    {
        return head;
    }
    pstLnCur = head;
    pstLnPre1 = &stLnHead1;
    pstLnPre2 = &stLnHead2;

    while(NULL != pstLnCur)
    {
        if(pstLnCur->val<x)
        {
            pstLnPre1->next = pstLnCur;
            pstLnPre1 = pstLnPre1->next;
        }
        else
        {
            pstLnPre2->next = pstLnCur;
            pstLnPre2 = pstLnPre2->next;
        }
        pstLnCur = pstLnCur->next;
    }
    pstLnPre2->next = NULL; //别忘链表尾节点需要赋值为空
    pstLnPre1->next = stLnHead2.next;

    return stLnHead1.next;
}

/*struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode stLnHead1 = {0};
    struct ListNode stLnHead2 = {0};
    struct ListNode* pstLnPre1 = NULL;
    struct ListNode* pstLnPre2 = NULL;
    if(NULL == head)
    {
        return head;
    }

    stLnHead1.next = head;
    pstLnPre1 = &stLnHead1;  
    pstLnPre2 = &stLnHead2;

    while(NULL != pstLnPre1->next)
    {
        if(x > pstLnPre1->next->val)
        {
            pstLnPre1 = pstLnPre1->next;
        }
        else
        {
            pstLnPre2->next = pstLnPre1->next;
            pstLnPre1->next = pstLnPre1->next->next;
            pstLnPre2 = pstLnPre2->next;
        }
    }
    pstLnPre2->next = NULL; //别忘链表尾节点需要赋值为空
    pstLnPre1->next = stLnHead2.next;

    return stLnHead1.next;
}*/
```