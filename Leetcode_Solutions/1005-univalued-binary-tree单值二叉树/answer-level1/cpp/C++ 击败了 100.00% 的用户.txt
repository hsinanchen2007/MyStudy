### 解题思路
![3.png](https://pic.leetcode-cn.com/3b16fc3e6a07fda10b966d3a1f8473d0391722f531259b46997abd484384942e-3.png)

### 代码
```cpp
class Solution {
public:
    set<int> tree;
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        tree.insert(root->val);
        if(tree.size()>1)return false;
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};
```