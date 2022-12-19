### 解题思路
1. 我们所需要做的就是把奇数下标的结点挑出来，插入到偶数前面
2. 比如说1 2 3 4 5 6 7 8，这里注意也是讨论下标
3. 我们需要把3 5 7挑出来依次插入到1 末尾
4. 这里考虑用两个指针，一个指针负责插入，指向奇数链表的末尾，一个负责筛选出奇数
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if(!head||!head->next)
    return head;
    struct ListNode *p1=head;//指向奇数
    struct ListNode *p2=head->next;//筛选出奇数
    struct ListNode *q;
    while(p2&&p2->next)
    {
        q=p2->next;//指向奇数
        p2->next=q->next;//修改指向为偶数
        p2=p2->next;
        q->next=p1->next;
        p1->next=q;
        p1=q;
    }
    return head;
}
```