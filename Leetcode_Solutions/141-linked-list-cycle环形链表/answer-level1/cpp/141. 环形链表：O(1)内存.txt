### 解题思路
双指针追赶，赶上则存在环。

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
    // 快慢指针，快指针追上慢指针则存在循环
    bool hasCycle(ListNode *head) {
        if(head == NULL)    return false;

        ListNode *slow = head;
        ListNode *quick = head->next;
        if(slow == quick)   return true;

        while(slow != quick) {
            if(slow == NULL)   return false;
            slow = slow->next;
            if(quick == NULL)  return false;
            quick = quick->next;
            if(quick == NULL) return false;
            quick = quick->next;
        }
        return true;
    }
};
```
![4.png](https://pic.leetcode-cn.com/fbca77b6a4361e3a8275499ee430af6a8b3d965492dce5a6f90cd5c8fc9cec1a-4.png)
