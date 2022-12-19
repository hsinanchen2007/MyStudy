### 解题思路
迭代 时间O(n) 

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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* nhead = new ListNode(1);
        nhead->next = head;
        if(head->val == val) return head->next;
        while(head && head->next){
            if(head->next->val == val){
                head->next= head->next->next;
            }
            head = head->next;
        }
        return nhead->next;
    }
};
```