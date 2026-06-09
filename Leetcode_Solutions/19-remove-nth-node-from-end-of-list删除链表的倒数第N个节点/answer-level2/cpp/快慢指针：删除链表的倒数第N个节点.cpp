### 解题思路
定义两个指针，快指针先出发到n+1的位置后，慢指针出发。当快指针走到null的时候，慢指针正好到位。
只需要对链表一次遍历。

![屏幕快照 2020-04-01 上午12.38.27.png](https://pic.leetcode-cn.com/a01903b8ea1185c6aeafe01cc465dea6f7b395fedf0179fd24040e6f602c226c-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-04-01%20%E4%B8%8A%E5%8D%8812.38.27.png)


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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast)
        {
            if(n < 0)
            {
                slow = slow->next;
            }
            else
            {
                n--;
            }
            fast = fast->next;
        }
        if(0 > n)
        {
            if(slow->next) slow->next = slow->next->next;
        }
        else
        {
            head = head->next;
        }
        return head;
    }
};
```