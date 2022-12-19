### 解题思路
将从第2个节点到第N个节点
依次逐节点插入到第1个节点(head节点)之后
最后将第一个节点挪到新表的表尾
前两个用例真的是忘了
[]和[1]特殊情况的考虑

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* a;
    struct ListNode* b;
    if(head==NULL||head->next==NULL)
        return head;
    a=head->next;//a指向第二个节点

    while(a->next != NULL)
    {
        b=a->next;//b指向a之后的一个节点
        a->next=b->next;//将a的后继节点改变成b的后继节点
        b->next=head->next;//原来头节点指向a，现在b指向a
        head->next=b;//b交换到a之前，则头节点指向b       
    }
    a->next=head;//当a到达末尾，让a与头节点相连
	head=a->next->next;//新head变为原head的next
	a->next->next=NULL;//断掉环
	return head;
}
```