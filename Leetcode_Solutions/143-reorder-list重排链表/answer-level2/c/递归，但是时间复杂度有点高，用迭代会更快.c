### 解题思路
1->2->3->4->5->6   //把它拆分
1->6->2->3->4->5

2->3->4->5
2->5->3->4
    
3->4   //两个数也交换，但还是3->4,不懂可以画图看

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swap(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    struct ListNode* phead = head;
    struct ListNode* pnext = head;
    while(phead->next)
    {
        pnext = phead;
        phead = phead->next;
    }
    pnext->next = NULL;   //此时phead 为链尾，pnext 为其前一个节点
    printf("%d %d\n",phead->val,pnext->val);
    phead->next = head->next;
    head->next = phead;   //此时phead 为链表的第二个节点
    swap(phead->next);  //因为并没有更改前面节点的next，所以后面节点的变更对前面的节点没有影响
    return head;
}
void reorderList(struct ListNode* head)
{
    swap(head);       
    return head;
}
```