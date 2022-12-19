先序遍历二叉树
首先将节点储存到路径中，然后sum=sum-val;继续遍历后续节点

如过是叶子节点并且sum==0的话就将路径加入

```
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
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
          preorder(root,sum);
          return ans;
    }
    void preorder(TreeNode* root, int sum)
    {
        if(root==nullptr) return;
        path.push_back(root->val);
        sum-=root->val;
        if(sum==0&&!root->left&&!root->right) ans.push_back(path);

        preorder(root->left,sum);
        preorder(root->right,sum);
        path.pop_back();
    }
};
```
