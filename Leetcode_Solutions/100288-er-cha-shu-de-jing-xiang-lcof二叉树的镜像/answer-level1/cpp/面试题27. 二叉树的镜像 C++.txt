### 解题思路
思路：
1.新构建一个二叉树，反向构建
**2.注意：新的根节点一定要初始化为空指针，否则会访问非法地址，一定切记**

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

    void dfs(TreeNode* root,TreeNode* &newroot){
        if(root == nullptr){
            return;
        }

        newroot = new TreeNode(root->val);
        dfs(root->left, newroot->right);
        dfs(root->right, newroot->left);

        return;
    }

    TreeNode* mirrorTree(TreeNode* root) {
        //一定要初始化成空指针，否则返回的是一个随机值，容易导致非法访问
        TreeNode *newroot = nullptr; 
        dfs(root,newroot);

        return newroot;
    }
};
```