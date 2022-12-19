### 解题思路
方法一：删除链表中的元素

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//方法一：删除链表中的元素
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode*    pCurNode    = head;
    struct ListNode*    pNextNode   = head;

    if(NULL == head) return head;

    pNextNode = pCurNode->next;
    while(pNextNode != NULL)
    {
        if(pCurNode->val == pNextNode->val)
        {
            pNextNode = pNextNode->next;
            pCurNode->next = pNextNode;
        }
        else
        {
            pCurNode = pNextNode;
            pNextNode = pNextNode->next;
        }
    }
    return head;
}
```