### 解题思路
输入的链表是没有头结点的。
注意考虑输入空链表的情况。
三个指针：新链表的头结点 旧链表的第一个节点 旧链表的第二个节点
用头插法把旧链表的第一个指针“头插法”到新链表中，旧链表的两个指针向后移动一下。
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
//输入空链表直接返回
    if(head==0)
        return 0;
//自己创建一个头结点方便操作
    struct ListNode headNode;
    struct ListNode* NewHead=&headNode;
    NewHead->next=0;
//旧链表的第一个节点是即将卸下并且插入新链表头部的节点，用iter指着。旧链表的头结点后移一个。
    struct ListNode* iter=head;
    head=head->next;
//循环头插法
    while(iter!=0)
    {
        iter->next=NewHead->next;
        NewHead->next=iter;
        iter=head;
        if(head!=0)
            head=head->next;
    }

    return NewHead->next;
}
```