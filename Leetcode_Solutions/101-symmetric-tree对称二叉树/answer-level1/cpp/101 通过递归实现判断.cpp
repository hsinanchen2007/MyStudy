判断两个二叉树是否为镜像：
1，根节点值相等
2，左树的左子树与右树的左子树为镜像关系，左树的右子树和右树的左子树为镜像关系。

### 代码

```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return mirror(root->left, root->right);
    }

private:
    vector<int> num;
    bool mirror(TreeNode* l, TreeNode* r) {
        if (l==nullptr && r==nullptr) //两个均空
            return true;
        if (l==nullptr || r==nullptr) //一空一不空
            return false;
        if (l->val==r->val && mirror(l->left, r->right) && mirror(r->left, l->right)) 
            return true;
        return false;
    }
};
```