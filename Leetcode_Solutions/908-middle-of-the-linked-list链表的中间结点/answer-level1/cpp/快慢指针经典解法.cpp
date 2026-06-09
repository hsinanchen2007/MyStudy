![捕获.PNG](https://pic.leetcode-cn.com/9eca28aed84fb30063b014dafca576bd054290c299ce73e7b57c5da9771a0891-%E6%8D%95%E8%8E%B7.PNG)

### 解题思路
这是快慢指针的经典解法，通过快慢指针移动速度的不同，来寻找到链表的中间结点，而最好的速度比为2:1，这样就可以使得当快指针到达链表尾的时候，慢指针刚好到达链表的中间结点，最后则可返回慢指针，即链表的中间结点。

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
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        ListNode* fast, *slow;
        fast = slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
```