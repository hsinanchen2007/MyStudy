### 解题思路
需要注意输出的格式，需要加上->

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>vc;
        if(root == NULL)
        {
            return vc;
        }
        DFS(root,vc,to_string(root->val));
        return vc;
    }
    void DFS(TreeNode* root,vector<string> &vc,string subPath){
       //叶子节点
        if(root->left == NULL && root->right == NULL)
        {
            vc.push_back(subPath);
            return;
        }
        //非叶子节点
        //如果左孩子节点不空
        if(root->left != NULL)
        {
            DFS(root->left,vc,subPath + "->" + to_string(root->left->val));
        }
        //如果右孩子节点不空
        if(root->right != NULL)
        {
            DFS(root->right,vc,subPath + "->" + to_string(root->right->val));
        }
    }
};
```