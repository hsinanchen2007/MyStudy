用时12ms
内存消耗18.1MB
```
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        //空树认为是符合要求的
        if(root == nullptr) return true;
        //若左子树非空且不是二叉搜索树
        if(root->left != nullptr && !isValidBST(root->left)) return false;
        //比较与更新当前结点
        if(root->val <= temp) return false;
        temp = root->val;
        //若右子树非空且不是二叉搜索树
        if(root->right != nullptr && !isValidBST(root->right)) return false;
        return true;
    }
private:
    //用INT_MIN不行。。。有测试用例数比较大
    long long int temp = LONG_MIN;
};
```
