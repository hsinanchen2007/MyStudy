### 解题思路

一开始的思路是，看到给的例子的形状，因为直径应该是root的左子树和右子树的最大深度之和

于是就写了一个递归找两个的最大深度。

```cpp
//思路不对，
class Solution1 {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        return left_depth + right_depth;
    }

    int depth(TreeNode* root){
        if (root == NULL) return 0;

        int left = depth(root->left) + 1;
        int right = depth(root->right) + 1;

        return left > right ? left : right;
        
    }

};
```

但是我错了，实际上有可能是在root的同一边有最低和最深的情况。

实际上，应该写成，找到left和right的深度，然后left+right和全局定义的长度比较，如果比全局的长，就更新全局值。

```cpp

class Solution {
    
public:
    int length = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return length;
    }

    int depth(TreeNode* root){
        if (root == NULL) return 0;

        int left = depth(root->left) ;
        int right = depth(root->right) ;
        length = max(length, left + right);

        return max(left, right) + 1;
        
    }

};

```