- 只要有一个`false`整个函数就false
- 边界：空结点`return true`
- 构建当前解`root->val == val && 左子树单值 && 有子树单值`

```cpp
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        val = root->val;
        return isUni(root);
    }
private:
    int val;
    bool isUni(TreeNode* root){
        if(!root) return true;
        return root->val == val && isUni(root->left) && isUni(root->right);
    }
};
```