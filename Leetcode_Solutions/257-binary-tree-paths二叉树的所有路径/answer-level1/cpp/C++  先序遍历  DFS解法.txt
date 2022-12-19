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
    vector<string> paths;
public:
    void dfs(TreeNode* root, vector<int>& res){
        res.push_back(root->val);
        if(!root->left && !root->right){   //递归边界
            string path = "";
            for(int i=0; i<res.size(); i++){
                path += to_string(res[i]);
                if(i!=res.size()-1) path += "->";
            }
            paths.push_back(path);
            res.pop_back();
            return;
        }else {
            if(root->left)  dfs(root->left, res);
            if(root->right) dfs(root->right, res);
            //回溯
            res.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        dfs(root, res);
        return paths;
    }
};



```