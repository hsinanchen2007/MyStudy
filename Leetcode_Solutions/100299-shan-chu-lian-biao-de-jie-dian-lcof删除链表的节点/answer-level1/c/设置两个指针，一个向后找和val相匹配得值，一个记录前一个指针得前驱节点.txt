### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val)
{
    struct ListNode* phead = head;     //记录前节点
    struct ListNode* cur = head;      //记录后节点
    if(head == NULL)
        return head;
    if(head->val == val)     //头节点为特殊节点，得单独处理
    {
        head = head->next;
        return head;
    }
    while(cur->next)
    {
        if(cur->val != val)
        {
            phead = cur;
            cur = cur->next;
        }
        else
            break;                   //此时cur 为所需删除的节点
    }
    phead->next = cur->next;
    return head;  
}
```