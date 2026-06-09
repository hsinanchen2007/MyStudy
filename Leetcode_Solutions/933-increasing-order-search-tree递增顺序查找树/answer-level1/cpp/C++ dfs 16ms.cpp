![image.png](https://pic.leetcode-cn.com/38902496bf8885ea468ba27c965c9e75f371ad0de4456ed670a1d2dd235d541e-image.png)

1.dfs右边
2.dfs左边
3.找到左边最大的，然后作为当前root的根，over


```
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (root->right != nullptr) {
            root->right = increasingBST(root->right);
        }
        if (root->left != nullptr) {
            auto newRoot = increasingBST(root->left);
            root->left = nullptr;
            TreeNode* father = newRoot;
            while (father->right != nullptr) {
                father = father->right;
            }
            father->right = root;
            return newRoot;
        }
        return root;
    }
};
```
