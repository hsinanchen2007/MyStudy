### 解题思路
一个指针走一步，另一个指针走两步，当第二个指针走到队尾时，第一个指针刚好走到中间节点。

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *p, *q;
        p = q = head;
        while ( q->next != NULL) {
            p = p->next;
            q = q->next;
            if (q->next != NULL)
                q = q->next;
        }
        return p;
    }
};
```