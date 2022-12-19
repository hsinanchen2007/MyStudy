### 解题思路
首先通过快慢指针，找到回文下半段的起点，可以举一些例子看一下更直观，每次快指针移动两次，慢指针移动一次，直到快指针到链表最后一个节点，慢指针的下一个就是回文下半段的第一个节点。之后将下半段翻转以后，与上半段一一对比即可。

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
        if (!head)             // empty list
            return true;

        ListNode *slow = head, *fast = head;

        while (fast->next) {      
            fast = fast->next;
            if (!fast->next)
                break;
            fast = fast->next;
            slow = slow->next;
        }

        if (fast == slow)   // only one node
            return true;
        
        fast = slow->next;
        slow = head;
        
        // reverse list
        ListNode *p = fast, *q = fast->next;
        while (q) {
            q = q->next;
            p->next->next = fast;
            fast = p->next;
            p->next = q;
        }

        // compare two lists
        while (fast) {
            if (fast->val == slow->val) {
                fast = fast->next;
                slow = slow->next;
            }
            else
                return false;
        }
        
        return true;
    }
};
```