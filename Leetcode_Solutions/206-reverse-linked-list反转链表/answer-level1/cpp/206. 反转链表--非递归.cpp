### 解题思路

执行用时 :8 ms, 在所有 C++ 提交中击败了70.83%的用户

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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode *reverseHead = NULL;
        ListNode *next = head;
        while(next != NULL){
            ListNode *cur = next;
            next = next->next;
            cur->next = reverseHead;
            reverseHead = cur;
        }
        return reverseHead;
    }
};
```