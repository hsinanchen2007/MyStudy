![image.png](https://pic.leetcode-cn.com/f2d4c43433caa0748bd17342b86757aa0ee71abefe7a967357d86712394011dc-image.png)

思路：
三种场景
1.如果大于R，则右枝都大于R，直接丢掉，递归左节点并返回；
2.如果小于L，则左枝都小于L，直接丢掉，递归右节点并返回；
3.否则分别递归处理左右节点，并返回当前节点。

```
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val > R) {
            return trimBST(root->left, L, R);
        }
        if (root->val < L) {
            return trimBST(root->right, L, R);
        }
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};
```
