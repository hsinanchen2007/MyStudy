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
    ListNode* swapPairs(ListNode* head) {
        int temp = 0;
        ListNode  *end = head;
        while(head != nullptr &&head->next != nullptr ){
            temp = head->val;
            head->val = head->next->val;
            head->next->val = temp;
            head = head->next->next;
        }
        return end;
    }
};
```