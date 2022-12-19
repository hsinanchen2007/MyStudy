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
    void traverseIn(vector<int> &res, TreeNode *x)
    {
        if(!x)return;
        traverseIn(res, x->right);  //访问右子树
        res.push_back(x->val);  //访问根节点
        traverseIn(res, x->left);  //访问左子树
    }
    int kthLargest(TreeNode* root, int k) {
        if(!root || k < 1)return -1;
        vector<int> res;
        traverseIn(res, root);
        return res[k-1];
    }
};
```