### 解题思路
双指针单次遍历
![image.png](https://pic.leetcode-cn.com/02eb837d4859516f153e86cbc9c0488f9fd689337670bce0a70dece6508d39ea-image.png)


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
        ListNode* cur = head;
        ListNode* ans = head;
        while(cur && cur->next)
        {
            ans = ans->next;
            cur = cur->next->next;
        }
        return ans;
    }
};
```