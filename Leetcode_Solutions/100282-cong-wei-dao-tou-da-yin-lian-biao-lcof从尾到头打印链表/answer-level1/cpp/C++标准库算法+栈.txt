### 解题思路
使用栈

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
        /*
        vector<int> res;
        while(head!=nullptr)
        {
            res.push_back(head->val);
            head=head->next;
        }
        reverse(res.begin(),res.end());
        return res;
        */
        stack<int> buffer;
        vector<int> res;
        while(head!=nullptr)
        {
            buffer.push(head->val);
            head=head->next;
        }
        while(!buffer.empty())
        {
            res.push_back(buffer.top());
            buffer.pop();

        }
        return res;


    }
};
```