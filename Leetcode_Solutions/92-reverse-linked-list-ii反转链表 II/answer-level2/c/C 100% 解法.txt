### 解题思路

如果 m 等于 n 不用反转直接返回
沿用反转整个链表的三指针方式，三个指针分别指向前一个节点、当前节点和后一个节点。
设指针 left 为 m 位置结点的前一个节点，right 为 n 位置的节点。
反转后，left->next 应为 n 位置的节点，right->next 应为 n->next 位置的节点。
以 1 2 3 4 5，m = 2， n = 4 为例：

![92.png](https://pic.leetcode-cn.com/e2bc00aa318a637d49b66ccd92f9b2c09aa2beeadc8f2df03302344b4d014959-92.png)

如果 m = 1 也就是从头节点开始反转，那么新的头节点应该为 n 位置的节点，
如果 m > 1 那么头节点没有变，还应该是 head

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    if (m == n)
        return head;

    struct ListNode *prev = NULL, *next = NULL, *p = head;
    // left is the m point left point, right is the m point
    // left->next should be the n point, right->next should be the n->next point
    struct ListNode *left = NULL, *right = NULL;
    int count = 1;
    while (p != NULL && count <= n)
    {
        next = p->next;

        if (count == m)
        {
            left = prev;
            right = p;
        }

        if (count >= m)
            p->next = prev;

        if (count == n)
        {
            if (left != NULL)
                left->next = p;
            right->next = next;

            // if reverse from the original head, the new head should locate on the n point
            // otherwise the head should be the original head
            if (m == 1)
                head = p;
        }

        prev = p;
        p = next;
        count++;
    }
    return head;
}
```