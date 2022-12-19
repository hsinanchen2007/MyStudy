### 解题思路
见代码
![image.png](https://pic.leetcode-cn.com/73d5edef9674da6b2b273947ece1f4e021efe06e349c57bd80a90e02d06b58d0-image.png)


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;
        while(pA != pB)
        {
            //注意这里是pA 不说pA -> next   
            pA = pA == nullptr ? headB : pA -> next;
            pB = pB == nullptr ? headA : pB -> next;
        }
        return pA;
    }
};
```