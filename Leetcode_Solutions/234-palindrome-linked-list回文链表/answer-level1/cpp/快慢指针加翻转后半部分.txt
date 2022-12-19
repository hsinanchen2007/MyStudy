### 解题思路
此处撰写解题思路

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
        if(!head||!head->next){
            return true;
        }

        ListNode* pre = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            fast = fast->next->next;
            ListNode* temp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = temp;
        }

        if(!fast->next){
            slow = slow->next;
        }else{
            ListNode* temp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = temp;
        }
        while(slow){
            if(pre->val != slow->val){
                return false;
            }
            pre = pre->next;
            slow = slow->next;
        }
        return true;
    }
};
```