### 解题思路
1.深度遍历二叉树，一旦遍历到叶子结点，就把存的路径path压入vector<string> paths中，清空path，再继续遍历所有的路径。

### 代码

```cpp
class Solution {
    string path;
    vector<string> res;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        backtrack(root);
        return res;
    }
    void backtrack(TreeNode* root) {
        if (!root) return;
        int len = path.size();                         
        path += (path.empty() ? "" : "->") + to_string(root->val);  
        if (!root->left && !root->right) res.push_back(path);       
        else{
            backtrack(root->left);
            backtrack(root->right);
        }        
        path.erase(path.begin() + len, path.end());    
    }
};

```