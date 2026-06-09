### 解题思路
双指针追逐

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
    int i=0;
    map<int,ListNode> A;
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;
        while (fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if (fast==slow){
                fast=head;
                while (fast != slow){
                    fast=fast->next;
                    slow=slow->next;
                }
                return fast;
            }
        }
        return NULL;
        
    }
};
```