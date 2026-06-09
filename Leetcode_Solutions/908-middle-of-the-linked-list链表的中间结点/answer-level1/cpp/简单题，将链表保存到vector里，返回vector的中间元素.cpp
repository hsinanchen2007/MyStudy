### 解题思路
如题

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
        vector<ListNode*> L;
        while(head != NULL){
            L.push_back(head);
            head=head->next;
        }
        return L[L.size()/2];
    }
};
```