此问题有两个难点：
1. 确定链表的中点以进行两路归并。
2. 两路归并。

首先进行中点的确认，用的是快慢指针的方法，快指针走两步，慢指针走一步，那么在遍历完链表的时候，慢指针指向的位置就是中点。
但是需要注意的是，由于链表是通过遍历来确定长度的，所以再确认完中点之后，需要切开链表，所以此时还需要用一个变量来保存中点节点的前驱，用以切断链表。

![image.png](https://pic.leetcode-cn.com/afcf1747cb95435f482d9a2e27fcb7e6528554b0d56e93b044a39680e7a93f3f-image.png)

```
ListNode* pmid;
ListNode* mid = head;
ListNode* trail = head;
while (trail && trail->next)
{
    pmid = mid;
    mid = mid->next;
    trail = trail->next->next;
}
pmid->next = NULL;
```


二路归并部分可以参看第21题：有两种解法：1.递归法 2.迭代法
https://leetcode-cn.com/problems/merge-two-sorted-lists/submissions/

递归法形式非常简单，可以欣赏一下，主要采用迭代法，技巧在于建立头节点，不断将两个链表中数值较小的节点插入到头节点后。
```
ListNode* twoWayMerge(ListNode* l1, ListNode* l2) {
    ListNode header(-1);
    ListNode *p = &header;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            p->next = l1;
            l1 = l1->next;
        }
        else
        {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }

    p->next = l1 == NULL ? l2 : l1;

    return header.next;
    }
```
总体代码如下：
```
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* pmid;
        ListNode* mid = head;
        ListNode* trail = head;
        while (trail && trail->next)
        {
            pmid = mid;
            mid = mid->next;
            trail = trail->next->next;
        }
        pmid->next = NULL;

        return twoWayMerge(sortList(head), sortList(mid));
    }

    ListNode* twoWayMerge(ListNode* l1, ListNode* l2) {
        ListNode header(-1);
        ListNode *p = &header;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        p->next = l1 == NULL ? l2 : l1;

        return header.next;
    }
};
```



