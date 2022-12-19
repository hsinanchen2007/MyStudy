### 解题思路
此处撰写解题思路

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
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        auto p = head;
        auto q = p->next;
        while (q) {
            
            auto r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        // 记得要把头指针(也就是改造后的最后一个指针设为0)
        head->next = nullptr;
        return p;
    }
};
```