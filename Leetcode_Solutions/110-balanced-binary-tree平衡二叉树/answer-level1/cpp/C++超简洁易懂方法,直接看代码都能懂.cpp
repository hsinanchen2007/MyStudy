```
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (root)
        {
            if (abs(height(root->left) - height(root->right)) > 1)
            {
                return false;
            }
            else //这里使用&&如果root的左子树或右子树有一个不满足情况就会返回false
                return isBalanced(root->left) && isBalanced(root->right);
        }
        //root为NULL时直接返回true，NULL时没有高度也没有子树
        return true;
    }
    int height(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        else
        { //这里要注意一定要用left_height和right_height保存值在进行判断，不然最后return时要进行两次递归运行时间就会变长
            int left_height = height(root->left);
            int right_height = height(root->right);
            return left_height > right_height ? left_height + 1 : right_height + 1; //别忘加一即算上root结点
        }
    }
};
```
