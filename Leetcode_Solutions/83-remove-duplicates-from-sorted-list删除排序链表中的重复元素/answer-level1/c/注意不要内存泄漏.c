### 解题思路
1. 注意会传入空链表
2. 设置两个指针，一个指向当前节点node，一个指向下一个节点next
3. 遍历整个链表，如果node->val == next->val，则将此next节点舍弃，
4. 如果node->val != next->val，则node和next节点均指向下一节点
5. 操作属于原地修改，返回头指针

/* 这里应该存一个变量把pnext给free掉，不然会内存泄漏，
不增加这里的free运行会击败98%用户，但是不合规范 */
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL) return NULL;

    struct ListNode *pnext = head->next;
    struct ListNode *pnode = head;
    struct ListNode *ptemp;
    int val = pnode->val;

    while (pnext != NULL)
    {
        if (pnode->val == pnext->val)
        {
            pnode->next = pnext->next;
            ptemp = pnext;
            pnext = pnext->next;
            free(ptemp);
            /* 这里应该存一个变量把pnext给free掉，不然会内存泄漏，
            不增加这里的free运行会击败98%用户，但是不合规范 */
        }
        else
        {
            pnode = pnext;
            pnext = pnext->next;
        }
    }
    return head;
}
```