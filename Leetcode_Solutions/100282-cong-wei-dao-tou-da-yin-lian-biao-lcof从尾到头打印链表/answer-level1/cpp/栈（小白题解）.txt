
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
    vector<int> reversePrint(ListNode* head) {
        if(head==NULL) return {};

        vector<int> res;
        stack<ListNode*> help;

        while(head!=NULL)
        {
            help.push(head);
            head=head->next;
        }

        while(!help.empty())
        {
            res.push_back(help.top()->val);
            help.pop();
        }

        return res;
    }
};
```