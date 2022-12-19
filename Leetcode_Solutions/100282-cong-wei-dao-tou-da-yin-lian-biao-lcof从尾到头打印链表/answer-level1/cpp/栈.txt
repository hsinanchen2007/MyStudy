### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/1134f96ba62ba55d083b7b1799e1bf0ced3d54a029a4d556a4b4f184a59ea5cb-image.png)

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
        ListNode* p=head;
        stack<int> st;
        vector<int> res;
        while(p)
        {
            st.push(p->val);
            p=p->next;
        }
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
```