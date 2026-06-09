### 解题思路
头插法
![image.png](https://pic.leetcode-cn.com/e79ede42ff5e27c31f4a9296093705c3a74e9f28f00ba113bfe473ce056afab1-image.png)

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
    struct ListNode reverHead = {0};
    reverHead.next = head;

    struct ListNode *p = &reverHead;
    struct ListNode *q = reverHead.next;
    int index = 0;
    while (index < m - 1) {
        q = q->next;
        p = p->next;
        index++;
    }
    for (int i = 0; i < n - m; i++) {
        struct ListNode *tmp = q->next;
        q->next = q->next->next;

        tmp->next = p->next;
        p->next = tmp;
    }
    return reverHead.next;
}
```