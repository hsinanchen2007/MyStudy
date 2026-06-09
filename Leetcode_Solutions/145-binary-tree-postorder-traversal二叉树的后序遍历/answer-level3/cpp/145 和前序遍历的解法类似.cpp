### 解题思路
前序遍历的顺序是根→左→右，后序遍历的顺序是左→右→根，倒过来便是根→右→左，和前序遍历实现方法类似，得到结果后再倒序输出即可。

### 代码

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        stack<TreeNode*> unprocessedList;
        while (curr || !unprocessedList.empty()) {
            while (curr) {
                res.push_back(curr->val);
                unprocessedList.push(curr->left);
                curr = curr->right;
            }
            curr = unprocessedList.top();
            unprocessedList.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```