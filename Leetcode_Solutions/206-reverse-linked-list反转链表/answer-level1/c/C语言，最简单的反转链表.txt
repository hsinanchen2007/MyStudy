要想反转一个链表，只需将头结点设为最后一个结点，再将原链表的下一个结点链接到该头结点上。不断循环，遍历一遍链表，即能将原链表反转。
时间复杂度：O（n）；
空间复杂度：O（1）；

```
代码块
```/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(!head)
    return head;//如果head为空，直接返回

    struct ListNode* p = head;
    struct ListNode* q;
    struct ListNode* s = NULL;
    while(p){
        q = p->next;//q用来保存原链表的下一个结点
        p->next = s;//将原链表的当前结点链接到新的链表上
        s = p;//更改新链表的头结点
        p = q;//让p指针重回原链表
    }
    return s;//反转完成后，s为新链表的头结点
}
