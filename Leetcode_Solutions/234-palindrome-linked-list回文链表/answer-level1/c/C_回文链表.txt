### 解题思路
链表没有头结点
快指针到末尾的时候慢指针到一半。如果链表为奇数个，快指针指向最后一个节点，慢指针指向的是链表中间的节点。如果链表为偶数个，快指针指向的是空，慢指针指向后半个链表的第一个节点。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//翻转链表
struct ListNode* fanZhuan(struct ListNode* Head)
{
    struct ListNode head;
    head.next=0;
    struct ListNode* n=Head;
    Head=Head->next;

    while(n!=0)
    {
        n->next=head.next;
        head.next=n;
        n=Head;
        if(Head!=0)
            Head=Head->next;
    }
    return head.next;
}

bool isPalindrome(struct ListNode* head){
    //空链表和只有一个节点的链表都是回文
    if(head==0||head->next==0)return 1;
    //快慢指针把链表分两半
    struct ListNode* slow=head;
    struct ListNode* fast=head;
    while(fast!=0&&fast->next!=0)
    {
        fast=fast->next;
        fast=fast->next;
        slow=slow->next;
    }
    struct ListNode* Head=fast==0?slow:slow->next;
    //后半个链表翻转顺序
    Head=fanZhuan(Head);

    //对比，看看是不是回文。
    while(Head!=0)
        if(head->val==Head->val)
        {
            head=head->next;
            Head=Head->next;
        }
        else
            return 0;
    return 1;
}
```