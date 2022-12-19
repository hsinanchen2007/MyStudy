### 解题思路
（1）重复递归调用直至到达叶子节点，这时已找到一条完整路径（path）
（2）用vector容器（paths）保存每次找到的一条完整路径（path）

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
class Solution 
{
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string>paths;
        construct_path(root,paths,"");
        return paths;
    }
    void construct_path(TreeNode* root,vector<string>(&paths),string path)
    {
        if (root!=NULL)
        {
            path+=to_string(root->val);
            if (root->left==NULL && root->right==NULL)
            {
                paths.push_back(path);
            }
            else
            {
                path+="->";
                construct_path(root->left,paths,path);
                construct_path(root->right,paths,path);
            }
        }
    }
};
```