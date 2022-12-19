### 解题思路
如代码里注释说的那样，有改进的空间

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // 两种思路，写一个函数，由树产生叶子序列，然后比较序列是否相同？
        // 定义一个函数，同时比较两者的叶子序列，一旦遇到不同的，停止函数，显然后一种更高效。前者好写
        vector<int> path1,path2;
        getPath(root1,path1);
        getPath(root2,path2);
        if(path1==path2) return true;
        else return false;
        
    }
    void getPath(TreeNode* root,vector<int>& path){
        if(!root) return;
        if(!root->left&&!root->right){
            path.push_back(root->val);
            return;
        }
        if(root->left) getPath(root->left,path);
        if(root->right) getPath(root->right,path);
        return;

    }
};
```