### 解题思路
给自己做笔记
一直纠结是否有不改动原链表结构的方法，发现并不存在。
注意奇数长度也可以算回文！

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
        ListNode *slow = head, *fast = head;
        ListNode *re = head, *re_prev = NULL;
        
        while (fast != NULL && fast->next != NULL) {
            re = slow;
            slow = slow->next;
            fast = fast->next->next;
            /* reverse slow */
            re->next = re_prev;
            re_prev = re;
        }
        
        /* odd len */
        if (fast != NULL)
            slow = slow->next;
        
        while (slow != NULL) {
            if (slow->val != re->val)
                return false;
            slow = slow->next;
            re = re->next;
        }
        
        return true;
    }
};
```