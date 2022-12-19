### 解题思路
方法一的引用传值不需要清空数组；
方法二的全局变量需要清空数组

### 代码

```cpp
class Solution {
public:
    void binaryTree(TreeNode* root,string path,vector<string>&res)
    {
        if(root==NULL) return ;
        path.append(to_string(root->val));
        path.append("->");
        if(root->left==NULL&&root->right==NULL) {path.erase(path.length()-2);res.push_back(path);}
        binaryTree(root->left,path,res);
        binaryTree(root->right,path,res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string>res;
        binaryTree(root,path,res);
        return res;
    }
};

```

方法二(参考其他题解)
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
        int len = path.size();                          // 记录初始状态（记住长度）
        path += (path.empty() ? "" : "->") + to_string(root->val);  // 改变状态（增加长度）
        if (!root->left && !root->right) res.push_back(path);       // 符合条件则添加至 res
        else backtrack(root->left), backtrack(root->right);         // 否则递归进入左右子树
        path.erase(path.begin() + len, path.end());     // 恢复初始状态（擦去新增的长度）
    }
};
```
