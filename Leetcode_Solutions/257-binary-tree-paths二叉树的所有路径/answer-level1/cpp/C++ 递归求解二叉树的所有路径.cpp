### 解题思路

很简单的问题，对于这种二叉树遍历的问题，使用递归的话，解题框架是一样的
```cpp
void dfs(TreeNode* root){
    if(!root) return;
    /*
        这里填写你对节点要做的处理：
        1. 遍历所有节点  v.push_back(root->val);
        2. 叶子节点单处理：
         if(!root->left && !root->right){
             ...
         }
        3. 等等...
    */
    dfs(root->left);
    dfs(root->right)
}
```

### 代码
```cpp
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        dfs(root, v, "");
        return v;
    }
private:
    // 参数 prev 保存父节点的字符串
    void dfs(TreeNode* root, vector<string>& v, string prev){
        if(!root) return;
        // 叶子节点
        if(!root->left && !root->right){
            v.push_back(prev + to_string(root->val));
        }else{
            prev = prev + to_string(root->val) + "->";
        }
        dfs(root->left, v, prev);
        dfs(root->right, v, prev);
    }
};
```