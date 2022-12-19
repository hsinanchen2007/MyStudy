### 简介
熟悉二叉树遍历方法 配合STL库可快速求解。有问题随时联系我。

```
class Solution {
public:
  vector<vector<int>> res;
  //  testcase: [3,9,20,null,null,15,7,20,16,30,12,null,12,14,null,null]
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    goDeeper(root, 0);
    reverse(res.begin(),res.end());
    return res;
  }

  void goDeeper(TreeNode *node, int depth) {
    if (node != NULL) {
        if(res.size() <= depth)
        {
            res.push_back(vector<int>());
        }
      res[depth].push_back(node->val);
    } else {
        // cout << "[depth:" << depth<<"]";
      return;
    }

    goDeeper(node->left, depth + 1);
    goDeeper(node->right, depth + 1);
  }
};
```
