### 解题思路
此处撰写解题思路
快慢指针。
![捕获.PNG](https://pic.leetcode-cn.com/f21fdc79cfbb3981fc9b89e203e5b30544499642706f57e33adba021b9ca6441-%E6%8D%95%E8%8E%B7.PNG)

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
        if (!head || !head->next) return head;
        ListNode *fast = head->next;
        ListNode *slow = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->next;

    }
};
```