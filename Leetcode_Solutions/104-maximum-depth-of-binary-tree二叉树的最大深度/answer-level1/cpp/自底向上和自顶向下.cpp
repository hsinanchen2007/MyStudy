### 解题思路
小白的我做递归算法时，老喜欢把自己带入递归中，越弄越糊涂。实际上，二叉树的遍历无非是自底向上和自顶向下这两种。
自底向上：从左右节点看往根节点。base case则是把最下端的子节点看作是初始值。
自顶向下：从根节点看往左右子节点。base case则是把最下端的子节点看作是终止值。

PS. base case往往对应if(root) == NULL这个退出条件。

自底向上方法。
### 代码

```cpp
class Solution {
public:
    int helper(TreeNode* root){
        if(root == NULL)
        return 0;             //最下端的子节点看作是初始值时表示第0层
        int left = helper(root->left) +1;
        int right = helper(root->right) +1;
        return max(left,right);
    }
    int maxDepth(TreeNode* root) {
        return helper(root);
    }
};
```
自顶向下方法
### 代码
```cpp
class Solution {
public:
    int helper(TreeNode* root, int level){
        if(root == NULL)
        return level;     //最下端的子节点看作是终止值时表示最大层
        return max(helper(root->left, level+1),helper(root->right, level+1));
    }
    int maxDepth(TreeNode* root) {
        return helper(root, 0);
    }
};
```