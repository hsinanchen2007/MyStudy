### 解题思路

其实这个问题就是 **求节点和**的变化版。

在 **[二叉树的所有路径](https://leetcode-cn.com/problems/binary-tree-paths/)** 这个问题中，我已经小小总结过一次了，呐：**[我的小总结](https://leetcode-cn.com/problems/binary-tree-paths/solution/c-di-gui-qiu-jie-er-cha-shu-de-suo-you-lu-jing-by-/)**

今天对总结再来补充补充：
```c++
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

**对二叉树求和，使用带返回值的递归**
```cpp
int dfs(TreeNode* root){
    if(!root) return 0;
    /*
        这里填写你对节点要做的处理：
        1. 对节点求和：
            if(!root->left && !root->right){
                return root->val;
            }
    */
    int left = dfs(root->left);
    int right = dfs(root->right);
    return left + right + root->val;
}
```

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
    int findTilt(TreeNode* root) {
        dfs(root);
        return result;
    }
private:
    int dfs(TreeNode* root){
        if(!root) return 0;
        // 叶子节点, 直接返回即可，不需要再访问左右孩子（叶子节点坡度为0）
        if(!root->left && !root->right){
            return root->val;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        result += abs(left - right);
        return left + right + root->val;
    }
private:
    int result = 0;
};
```