### 解题思路
此处撰写解题思路

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, int> counts;
    vector<TreeNode*> ans;
    serialize(root, counts, ans);
    return ans;
  }
private:
  string serialize(TreeNode* root, 
    unordered_map<string, int>& counts,
    vector<TreeNode*>& ans) {
    if (!root) return "#";
    string key = to_string(root->val) + "," 
        + serialize(root->left, counts, ans) + "," 
        + serialize(root->right, counts, ans);
    if (++counts[key] == 2)
      ans.push_back(root);
    return key;
  }
};
```