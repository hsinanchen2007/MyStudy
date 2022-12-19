### 解题思路

![image.png](https://pic.leetcode-cn.com/b5cade65ff2abfd36b2eb81650b81db90bffd47c2f38b363f472e21492472c94-image.png)

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
        stack<int> s;
        while(head!=NULL)
        {
            s.push(head->val);
            head=head->next;
        }
        vector<int> ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
```