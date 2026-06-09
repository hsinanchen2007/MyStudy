### 解题思路
链表删除比较简单，解题思路如下：
1 入参判断
2 判断头节点的值是否与val相同
3 判断其他节点是否与val相同
4 返回头节点

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
    //入参判断
    if(head == NULL)
    {
        return head;
    }

    if(head->val == val)
    {
        head = head->next;
        return head;
    }

    struct ListNode *prev = head;
    struct ListNode *curr = head->next;
    while(curr->val != val)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    return head;
}
```