### 解题思路
思路概述：从前往后递归交换两个结点，直至全部交换或仅剩一个节点
1. 如果正好全部交换，最后一次递归head为null，并返回，
-  使得链表最后一个结点的next域为null
2. 如果链表个数为奇数，最后还剩下一个节点，那么返回这个节点，
-  使得链表倒数第二个节点的next指向它

例如： 1 2 3 4 5
第一次递归：12	1->4	2->1	return 2

第二次递归：34	3->5	4->3	return 4

第三次递归：5	return5
最终链表为：2->1->4->3->5


### 代码

```c
struct ListNode* swapPairs(struct ListNode* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        return head;
    }
    struct ListNode* pre=head;
    struct ListNode* p=head->next;
    pre->next=swapPairs(p->next);
    p->next=pre;
    return p;
}
```