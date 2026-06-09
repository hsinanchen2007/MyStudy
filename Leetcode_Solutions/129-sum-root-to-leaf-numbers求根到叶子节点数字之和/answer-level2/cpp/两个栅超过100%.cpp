### 解题思路


### 代码

```cpp
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        stack<pair<TreeNode*, int>> s;
        stack<pair<TreeNode*, int>> s1;
        if (!root) return 0;
        s.push(pair<TreeNode*, int>(root, root->val));
        int re = 0;
        while (!s.empty()) {
            while (!s.empty()) {
                TreeNode* child1 = s.top().first->left;
                TreeNode* child2 = s.top().first->right;
                if (NULL == child1 && NULL == child2) {
                    re += s.top().second;
                }
                else {
                    if (NULL != child1) {
                        int a = 10 * s.top().second + child1->val;
                        s1.push(pair<TreeNode*, int>(child1, a));
                    }
                    if (NULL != child2) {
                        int a = 10 * s.top().second + child2->val;
                        s1.push(pair<TreeNode*, int>(child2, a));
                    }
                }
                s.pop();
            }
            while (!s1.empty()) {
                s.push(s1.top());
                s1.pop();
            }
        }
        return re;
    }
};
```