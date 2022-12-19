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
  int maxLevelSum(TreeNode* root) {
    vector<int> lsum;
    DFS(root, 0, lsum);
    return std::distance(lsum.begin(), 
      max_element(lsum.begin(), lsum.end())) + 1;
  }

  void DFS(TreeNode* root, 
    int dep, vector<int> &lsum) {
    if (!root) return;

    if (dep >= lsum.size())
      lsum.push_back(0);
    lsum[dep] += root -> val;

    DFS(root->left, dep + 1, lsum);
    DFS(root->right, dep + 1, lsum);
  }


};

```