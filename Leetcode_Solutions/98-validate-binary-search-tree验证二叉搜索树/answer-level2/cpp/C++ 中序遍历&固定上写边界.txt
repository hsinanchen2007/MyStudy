## 中序遍历

对于二叉搜索树的中序遍历，就是递增序列；所以我们只需要在中序遍历的时候判断当前节点值是否大于上一个节点值，就可以判断是否是二叉搜索树。

## 固定上下边界

+ 节点的左子树只包含小于当前节点的数。
+ 节点的右子树只包含大于当前节点的数。
+ 所有左子树和右子树自身必须也是二叉搜索树。

这是二叉树的性质，对于节点的右子树而言，右子树是有一个下界的，即右子树的所有节点必须都大于这个下界；同理左子树都有一个上界，即左子树所有节点都不得超过这个上界。

代码：

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // 方法1. 中序遍历
        /*if(!root) return true;
        dfs(root);
        return isValid;*/

        // 方法2. 前序遍历比较上下边界
        return helper(root, LONG_MAX, LONG_MIN);
    }
private:
    bool helper(TreeNode* root, long upper, long lower){
        if(!root) return true;
        if(root->val <= lower)
            return false;
        if(root->val >= upper)
            return false;
        return helper(root->left, root->val, lower) && helper(root->right, upper, root->val);
    }

private:
    void dfs(TreeNode* root){
        if(isValid && root){
            dfs(root->left);
            if(root->val <= prev){
                isValid = false;
            }else{
                prev = root->val;
            }
            dfs(root->right);
        }
    }
private:
    bool isValid = true;
    long prev = LONG_MIN;
};
```