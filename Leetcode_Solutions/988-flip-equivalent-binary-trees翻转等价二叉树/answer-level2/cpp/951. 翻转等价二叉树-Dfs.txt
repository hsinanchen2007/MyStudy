Dfs遍历所有节点，当节点值不一致时，镜像翻转该节点，再比较一次。
技巧：不必真的翻转，只需要更换比较入参再次递归遍历即可。
```
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        } else if (root1 == nullptr && root2 != nullptr) {
            return false;
        } else if (root1 != nullptr && root2 == nullptr) {
            return false;
        }

        if (root1->val != root2->val) {
            return false;
        }

        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};
```
