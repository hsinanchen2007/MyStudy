### 解题思路
    用到之前的92. 反转链表 II reverseBetween, 这边需要注意len(list) > k 要直接返回原来的链表

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
        ListNode dm{0};
        ListNode *dummy = &dm;
        ListNode *pre, *p = head, *q, *begin = dummy, *end;
        dummy->next = head;

        if (m <= 0 || n <= m) {
            return head;
        }

        int idx = 1;
        
        if (p->next && idx != n) {
            // 移动到 idx = m 
            while (idx < m && p->next) {
                begin = p;
                p = p->next;
                idx++;
            }

            pre = p;
            end = p;
            p = p->next;
            while (p && idx != n) {
                q = p->next;
                p->next = pre;
                pre = p;
                p = q;
                idx++;
            }

            begin->next = pre;
            end->next = p;
        }
        return dummy->next;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }

        int len = 1;
        ListNode* p = head;
        while (p->next) {
            p = p->next;
            len++;
        }
        if (k > len) {
            return head;
        }
        if (k == len) {
            return reverseBetween(head,  1, len);
        }
        std::cout << "len = " << len << std::endl;
        int times = len / k;
        std::cout << "times = " << times << std::endl;
        ListNode *res = nullptr;
        for (int i = 1; i <= times * k - 1;) {
            res = reverseBetween(head, i, i + k - 1);
            head = res;
            i +=k;
        }
        return res;

    }
};
```