思路:用一个长度为2的ListNode*数组存储遍历到的节点，当数组满了或者链表遍历完了就从数组尾开始将数组元素加到结果链表ans末尾
- 55/55 cases passed (4 ms)
- Your runtime beats 89.76 % of cpp submissions
- Your memory usage beats 84.79 % of cpp submissions (8.6 MB)

```
class Solution {
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *a[2];
        ListNode *p = new ListNode(0);
        ListNode *q = p;
        ListNode *r;
        int i = 0;
        while (head != NULL)
        {
            r = head;
            head = head->next;
            r->next = NULL;
            a[i++] = r;
            if (i == 2 || head == NULL)
            {
                while (i > 0)
                {
                    q->next = a[i - 1];
                    q = q->next;
                    i--;
                }
            }
        }
        return p->next;
    }
};
```
