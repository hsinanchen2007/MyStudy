### 解题思路

这个问题一看就可以使用递归来做。

首先有几个条件我们来梳理一下：
```cpp
如果根节点的左右孩子不为空，则 left->val += 10 * root->val;
最后的总路径和，sum 为所有叶子节点值的和

那么递归什么时候结束呢？
1. 根节点为空
2. 根节点的左右节点为空，返回根节点的值
```

我写了两个版本的递归代码，其实都是差不多的啦~~

### 代码 1.

```cpp
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        dfs(root,0);
        return sum;
    }
private:
    // 参数 preVal保存父节点的值
    void dfs(TreeNode* node,int preVal){
        if(!node) return;
        // 子节点累加
        node->val += 10 * preVal;
        if(!node->left && !node->right){
            sum += node->val;
        }
        dfs(node->left, node->val);
        dfs(node->right, node->val);
    }
private:
    int sum = 0;
};
```

### 代码 2. 
```cpp
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        return dfs(root,0);
    }
private:
    // 参数 preVal保存父节点的值
    int dfs(TreeNode* node,int preVal){
        if(!node){
            return 0;
        }
        // 子节点累加
        node->val += 10 * preVal;
        if(!node->left && !node->right){
            return node->val;
        }
        // 左子树叶子节点值
        int left = dfs(node->left, node->val);
        // 右子树叶子节点值
        int right = dfs(node->right, node->val);
        return left + right;
    }
};
```