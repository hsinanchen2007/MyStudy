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
        //没啥好说的，快慢指针
          ListNode* fast=head;
          ListNode* slow=head;
          while(fast!=NULL && fast->next!=NULL)
          {
              slow=slow->next;
              fast=fast->next->next;
          }
          return slow;
    }
};
```