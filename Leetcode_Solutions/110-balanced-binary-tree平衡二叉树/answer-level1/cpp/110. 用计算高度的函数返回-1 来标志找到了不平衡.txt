![image.png](https://pic.leetcode-cn.com/f86e637377d0fa521b83f021536de202f67b43c1a8f0a286634afd4e21180abb-image.png)

### 用高度为-1来标志发现了不平衡
由于二叉树的高度不可能是-1，因此可以使用计算高度的函数：
    1. 发现不平衡则返回-1.
    2. 没有发现不平衡则返回子树高度。

我们的辅助函数有两个作用，一个是计算高度，一个是发现不平衡。因此命名为countHeightAndFindNoBalance。
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
    bool isBalanced(TreeNode* root) {
        if(countHeightAndFindNoBalance(root)==-1){
            return false;
        }else{
            return true;
        }
    }
    int countHeightAndFindNoBalance(TreeNode* root){
        if(root == nullptr) return 0;
        int leftHeight = countHeightAndFindNoBalance(root->left);
        if(leftHeight==-1){
            return -1;
        }
        int rightHeight = countHeightAndFindNoBalance(root->right);
        if(rightHeight == -1) {
            return -1;
        }
        if(leftHeight-rightHeight>1 || leftHeight-rightHeight<-1){
            return -1;
        }else{
            return 1+max(leftHeight,rightHeight);
        }
    }
    
};
```