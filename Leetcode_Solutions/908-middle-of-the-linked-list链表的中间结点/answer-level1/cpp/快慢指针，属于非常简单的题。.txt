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
    ListNode* middleNode(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;

        ListNode * low=head, *fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            low=low->next;
        }

        return low;
    }
};
```