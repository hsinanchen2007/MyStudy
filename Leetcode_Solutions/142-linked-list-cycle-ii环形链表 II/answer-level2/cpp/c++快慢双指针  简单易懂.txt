### 解题思路
![UX(3MZE}11XS5)GBDS58{}B.png](https://pic.leetcode-cn.com/b1a095215073a2c7219fb23af166b1ba1acfcfaae17475b7007b846b973a0692-UX\(3MZE%7D11XS5\)GBDS58%7B%7DB.png)
快指针一次走两步，慢指针一次走一步，当快指针遇到慢指针时，快指针回到头结点
然后快慢指针都一次走一步，当起再次相遇时即为环的起点。
证明 可用数学归纳法。


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
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast -> next)
        {
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow) 
            {
                fast = head;
                while(fast != slow)
                {
                    fast = fast -> next;
                    slow = slow -> next;
                }
                return fast;
            }
        }
        return NULL;
    }
};
```