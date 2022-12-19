### 解题思路
注意保存cur指针

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *fast = head->next->next;
        ListNode *slow = head;
        ListNode *root = head->next, *cur = root;
        bool tag = false;
        while(fast != NULL){
            cur->next = slow->next;
            slow->next->next = slow;
            slow->next = fast;
            cur = slow;
            if(fast->next == NULL){
                tag = true;
                break;
            }
            slow = fast;
            fast = fast->next->next;
        }
        if(!tag){
            cur->next = slow->next;
            slow->next->next = slow;
            slow->next = fast;
        }
        return root;
    }
};
```