### 解题思路
先对k处理，去掉重复操作的次数，然后找到目标点，直接将目标点之后的链接到头部即可。

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        int len = 0;
        ListNode* p = head;
        while(p != NULL)
        {
            len++;
            p = p->next;
        }
        k %= len;
        if(k == 0)
            return head;
        ListNode *q;
        p = head;
        int cnt = 1;
        while(len - cnt > k)
        {
            p = p->next;
            cnt++;
        }
        q = p->next;
        ListNode* newHead = q;
        p->next = NULL;
        while(q != NULL && q->next != NULL)
            q = q->next;
        q->next = head;
        return newHead;
    }
};
```