### 解题思路
回溯的方式，一定要记住：一条路径走完以后，要弹出栈。

传引用和传值的区别：
如果是传引用，&path,每次遍历完都要回溯
如果是传值，path,值不会被更新，不需要回溯

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
    vector<string> vec;
    string path;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
        {
            return vec;
        }
        if(!root->left && !root->right)
        {
            path += to_string(root->val); //叶节点后面不需要再加->
            vec.push_back(path);
            return vec;
        }
        path += to_string(root->val) +"->";
        string path2 = path;
        binaryTreePaths(root->left);
        path = path2; //回溯，递归后撤销选择
        binaryTreePaths(root->right);
        path = path2; //回溯，递归后撤销选择
        return vec;
    }
};
```