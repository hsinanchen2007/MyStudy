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
    vector<int> reversePrint(ListNode* head) {
        vector<int>res;
        stack<int>Stack;
        while(head!=NULL)
        {
            Stack.push(head->val);
            head=head->next;
        }
        while(Stack.size())
        {
            int temp=Stack.top();
            res.push_back(temp);
            Stack.pop();
        }
        return res;
    }
};
```