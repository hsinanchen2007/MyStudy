### 解题思路
详见：203. 移除链表元素

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//后处理头结点
struct ListNode* deleteNode(struct ListNode* head, int val){
    struct ListNode* pstLnPre = NULL;
    if(NULL == head)
    {
        return head;
    }

    pstLnPre = head;
    while(NULL != pstLnPre->next)
    {
        if(val == pstLnPre->next->val)
        {
            pstLnPre->next = pstLnPre->next->next;
        }
        else
        {
            pstLnPre = pstLnPre->next;
        }
    }

    if(val == head->val)
    {
        head = head->next;
    }

    return head;
}

//先处理头结点，总体计算量会小一些
struct ListNode* deleteNode(struct ListNode* head, int val){
    struct ListNode* pstLnPre = NULL;
    if(NULL == head)
    {
        return head;
    }
    while(val == head->val)
    {
        if(NULL != head->next)
        {
            head = head->next;
        }
        else
        {
            return NULL;
        }
    }

    pstLnPre = head;
    while(NULL != pstLnPre->next)
    {
        if(val == pstLnPre->next->val)
        {
            pstLnPre->next = pstLnPre->next->next;
        }
        else
        {
            pstLnPre = pstLnPre->next;
        }
    }

    /*if(val == head->val)
    {
        head = head->next;
    }*/

    return head;
}
```