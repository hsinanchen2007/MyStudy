很明显和有个数组的单调栈解法类似，那道题直接用栈倒着来，这道题也类似，如下。但是应该也可以用递归来解
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        ListNode* node = head;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        
        int n = v.size();
        stack<int> st;
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= v[i]) st.pop();
            ans[i] = st.empty() ? 0 : st.top();
            st.push(v[i]);
        }
        return ans;
    }
};
```