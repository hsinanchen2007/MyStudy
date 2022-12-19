### 解题思路

执行用时 :12 ms, 在所有 C++ 提交中击败了26.22%的用户

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
        stack<ListNode*> s;
        ListNode* next = head;
        while(next != NULL){
            s.push(next);
            next = next->next;
        }
        ListNode *reverseHead = s.top();
        next = reverseHead;
        s.pop();
        while(!s.empty()){
            next->next = s.top();
            next = next->next;
            s.pop();
        }
        next->next = NULL;
        return reverseHead;
    }
};
```