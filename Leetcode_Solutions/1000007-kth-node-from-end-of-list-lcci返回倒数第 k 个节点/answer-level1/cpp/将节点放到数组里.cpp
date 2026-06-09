
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
    int kthToLast(ListNode* head, int k) {
        vector<ListNode*> help;
        while(head!=NULL)
        {
            help.push_back(head);
            head=head->next;
        }
        int n=help.size();
        return help[n-k]->val;
    }
};
```