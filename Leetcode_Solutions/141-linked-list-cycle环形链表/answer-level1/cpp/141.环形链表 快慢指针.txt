### 解题思路

![image.png](https://pic.leetcode-cn.com/0be4ea8fd0eb9f14b4c8452861ed9b3c1dfba601410591d94576d3c3c907edfc-image.png)
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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode * quick = head;
        ListNode * slow = head;
        while (quick && slow) {
            if (!slow->next || !quick->next || !quick->next->next) return false;
            quick = quick->next->next;
            slow = slow->next;
            if (quick == slow) return true;
        }
        return false;
    }
};
```