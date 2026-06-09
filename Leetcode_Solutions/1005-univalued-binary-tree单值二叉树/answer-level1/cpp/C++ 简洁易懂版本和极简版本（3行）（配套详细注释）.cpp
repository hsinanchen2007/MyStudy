```
/*
简洁版（易理解）
*/
class Solution
{
public:
    bool isUnivalTree(TreeNode *root)
    {
        if (!root || (!root->left && !root->right)) //如果当前结点为空或者结点的左右子树都为空（没有人可以与其比较），则为true
        {
            return true;
        }
        if (!root->left && root->right) //如果节点的左子树为空，右子树不为空，则先判断其与右子树根节点的值是否相等，再递归判断右子树
        {
            return (root->val == root->right->val) && isUnivalTree(root->right);
        }
        else if (root->left && !root->right) //同理，如果节点的右子树为空，左子树不为空，则先判断其与左子树根节点的值是否相等，再递归判断左子树
        {
            return (root->val == root->left->val) && isUnivalTree(root->left);
        }
        if (root->val == root->left->val && root->val == root->right->val) //如果该节点左子树右子树都不为空且三者值相等，则递归判断其左右子树
        {
            return isUnivalTree(root->left) && isUnivalTree(root->right);
        }
        return false; //不符合以上情况的则返回false
    }
};
/*
由简洁版修改的更加精简的版本（三行）
*/
class Solution
{
public:
    bool isUnivalTree(struct TreeNode *root)
    {
        bool left_correct = (root->left == NULL || (root->val == root->left->val && isUnivalTree(root->left)));
        bool right_correct = (root->right == NULL || (root->val == root->right->val && isUnivalTree(root->right)));
        return left_correct && right_correct;
    }
};
```
