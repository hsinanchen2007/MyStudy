### 解题思路
执行用时 :
36 ms
, 在所有 C++ 提交中击败了
21.09%
的用户
内存消耗 :
15.7 MB
, 在所有 C++ 提交中击败了
5.01%
的用户

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
        if(head == NULL || head->next == NULL) return true;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != NULL && fast ->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow = head;
        ListNode* cur = NULL;
        ListNode* tmp;
        while(fast != NULL){
            tmp = fast;
            fast = fast->next;
            tmp->next = cur;
            cur = tmp;
        }
        while(cur != NULL && slow != NULL){
            if(cur->val != slow->val) return false;
            cur = cur->next;
            slow = slow->next;
        }
        return true;
    }
};
```