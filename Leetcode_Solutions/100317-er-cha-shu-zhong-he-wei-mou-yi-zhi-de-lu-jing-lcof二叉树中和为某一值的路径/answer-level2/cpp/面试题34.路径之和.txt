### 解题思路
递归遍历二叉树

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        int path_value=0;
        preoder(root,path_value,sum,path,result);
        return result;
    }
private:
    void preoder(TreeNode* node,int path_value,int sum,
                vector<int> &path,
                vector<vector<int>> &result)
    {
        if(!node)
        {
            return ; 
        }
        path.push_back(node->val);
        path_value+=node->val;
        if(!node->left&&!node->right&&path_value==sum)
        {
            result.push_back(path);
        }
        preoder(node->left,path_value,sum,path,result);
        preoder(node->right,path_value,sum,path,result);
        path_value-=node->val;
        path.pop_back();
    }
};
```