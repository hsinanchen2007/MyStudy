### 解题思路
为什么要用快慢指针呢，因为我们要获取前一半链表，所以当快指针到达末尾时，因为慢指针的速度是其一半，那么这时慢指针就到了中间位置，之后从中间向两边扩展判断回文即可。

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
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return true;
        ListNode* pre, *now, *slow = head, *fast = head;
        pre = NULL;
        now = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            if(fast != NULL && fast->next != NULL)
                fast = fast->next->next;
            ListNode* next = now->next;
            now->next = pre;
            pre = now;
            now = next;
        }
        if(fast != NULL && slow != NULL)
            slow = slow->next;
        while(slow != NULL && pre != NULL)
        {
            if(pre->val != slow->val)
                return false;
            slow = slow->next;
            pre = pre->next;
        }
        return true;
    }
};
```