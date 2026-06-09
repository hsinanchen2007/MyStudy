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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<string> res;
        DFS(root,res,"");
        return res;
    }
    //对于每一个节点，如果是叶节点，就加上叶节点的路径，同时压入vector,返回，若不是，就递归
    void DFS(TreeNode* root,vector<string> &vec,string path)//用引用的方式，直接对vector做更改
    {
        path+=to_string(root->val);
        if(root->left==NULL&&root->right==NULL)//没有分支，就压入容器,返回。递归结束点
        {
            vec.push_back(path);
            return;
        }
        if(root->left!=NULL) //有左分支，只需跟新string
            DFS(root->left,vec,path+"->");
        if(root->right!=NULL)    
            DFS(root->right,vec,path+"->");
    }
};
```