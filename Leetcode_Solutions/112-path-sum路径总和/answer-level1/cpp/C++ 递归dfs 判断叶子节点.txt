## 解法一

从根节点到叶子节点路径中，所有节点的值累加和等于**给定值sum**，即返回true。

很显然，递归问题。

```cpp
递归结束条件：
1. 根节点 root==nullptr
2. 当前节点为叶子节点，如果这一路径求和等于sum，即返回true
```

```cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        dfs(root,0,sum);
        return isEqual;
    }
private:
    // 参数 preVal为父节点的值
    void dfs(TreeNode* root, int preVal, int& sum){
        if(!root || isEqual) return;
        root->val += preVal;
        // 叶子节点
        if(!root->left && !root->right){
            if(root->val == sum){
                isEqual = true;
            }
        }
        dfs(root->left, root->val, sum);
        dfs(root->right, root->val, sum);
    }
private:
    bool isEqual = false;
};
```

## 解法二

这是对第一种方法的优化版，但是解题的思路是一样的。

```cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        sum -= root->val;
        // 是否是叶子节点
        if(!root->left && !root->right) return sum==0;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};
```