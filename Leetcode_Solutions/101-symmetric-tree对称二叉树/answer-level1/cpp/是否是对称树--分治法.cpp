### 解题思路
分治的几个点：
（1）当前的函数是否够用（返回值特别重要，不够用在自定义结构体）：看到对称树的特点是左子树的左等于右子数的右，左子树的右等于右子数的左，明显需要两个变量，所以自定义递归函数bool isSymmetric(TreeNode* left, TreeNode* right)；
（2）分：// 看左子树的左是不是等于右子数的右
        bool left_right = isSymmetric(left->left, right->right);
        // 看左子树的右是不是等于右子数的左
        bool right_left = isSymmetric(left->right, right->left);
（3）治：
        两个结果都满足就是对称树
        return left_right && right_left;

（4）递归结束：
        // 左右都空说明走到最后也没有返回false，那么就是对称树
        if(left == NULL && right == NULL){
             return true;
        }
        // 左右只有一个为空，那么肯定不是对称树了
        if(left == NULL || right == NULL) {
             return false;
        }
        // 当天两个是不是相等，不相等也不是对称树
        if(left->val!=right->val) {
            return false;
        }


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

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left==NULL && root->right==NULL) {
            return true;
        }
        if(root->left == NULL || root->right == NULL) {
            return false;
        }

        return isSymmetric(root->left, root->right);

    }

    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if(left == NULL && right == NULL){
             return true;
        }
        if(left == NULL || right == NULL) {
             return false;
        }
        if(left->val!=right->val) {
            return false;
        }

        bool left_right = isSymmetric(left->left, right->right);
        bool right_left = isSymmetric(left->right, right->left);

        return left_right && right_left;
    }
};
```