### 解题思路
特判第一下，m为1的时候单独处理。

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL)
            return NULL;
        if(m == n)
            return head;
        int cnt = 1;
        ListNode* pre = NULL, *now = head, *left = head, *init = head;
        if(m == 1)
        {
            ListNode* init = head;
            while(now != NULL)
            {
                if(cnt >= m && cnt <= n)
                {
                    ListNode* next = now->next;
                    now->next = pre;
                    pre = now;
                    now = next;
                }
                else if(cnt == n + 1)
                {
                    init->next = now;
                }
                else
                {
                    now = now->next;
                }
                cnt++;
            }
            return pre;
        }
        while(now != NULL)
        {
            if(cnt == m)
            {
                left = pre;
                init = now;
            }
            if(cnt >= m && cnt <= n)
            {
                ListNode* next = now->next;
                now->next = pre;
                pre = now;
                now = next;
            }
            else
            {
                pre = now;
                now = now->next;
            }
            if(cnt == n)
            {
                if(left != NULL)
                    left->next = pre;
                if(init != NULL)
                    init->next = now;
            }
            cnt++;
        }
        return head;
    }
};
```