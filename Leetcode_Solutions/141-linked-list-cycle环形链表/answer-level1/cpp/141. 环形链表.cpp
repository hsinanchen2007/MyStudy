## 快慢指针
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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        ListNode *slow=head, *fast=head->next; //慢指针从head开始走，快指针从head->next开始走
        while(slow!=fast){ //当快慢指针相遇时结束循环
            if(fast->next==NULL || fast->next->next==NULL) return false;
            slow = slow->next; //慢指针每次走一步
            fast = fast->next->next; //快指针每次走两步
        }
        return true;
    }
};
```