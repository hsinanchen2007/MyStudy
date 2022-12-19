### 解题思路
1. 设置两个vector一个存放结果，一个存放当前路径和
2. 深度优先搜索递归实现，向下遍历时vector才插入当前节点值
3. 当完成当前节点子树节点的遍历后，从vector中移除当前节点

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
 private:
  void pathSum_inner(TreeNode* node, vector<vector<int>>& all_path, int sum, vector<int>& inner_vec) {
    // process boundary condition
    if (node == NULL) { return; }
    int val = node->val;
    inner_vec.emplace_back(val);
    int next_sum = sum - node->val;
    // insert pathSum
    if (next_sum == 0 && node->left == NULL && node->right == NULL) {
      all_path.emplace_back(inner_vec);
      inner_vec.pop_back();
      return;
    }
    // search left subtree
    pathSum_inner(node->left, all_path, next_sum, inner_vec);
    // search right subtree
    pathSum_inner(node->right, all_path, next_sum, inner_vec);
    inner_vec.pop_back();
  }
 public:
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    // init vector<vector>
    vector<vector<int>> all_path;
    // process boundary condition
    if (root == NULL) { return all_path; }
    int val = root->val, next_sum = sum - root->val;
    vector<int> root_vec;
    root_vec.emplace_back(val);
    if (root->left == NULL && root->right == NULL && next_sum == 0) {
      all_path.emplace_back(root_vec);
    }
    // search left subtree
    pathSum_inner(root->left, all_path, next_sum, root_vec);
    // search right subtree
    pathSum_inner(root->right, all_path, next_sum, root_vec);
    
    return all_path;
  }
};
```