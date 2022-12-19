### 解题思路
与 #102 类似

```cpp
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> results = levelOrder(root);
        reverse(results.begin(), results.end());
        return results;
    }
};
```