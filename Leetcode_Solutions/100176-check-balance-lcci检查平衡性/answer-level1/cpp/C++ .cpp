### 解题思路
书中的两种解法


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

    //方法1、 计算每个节点的左右子树高度差  效率不高，大量重复计算节点的高度
    bool isBalanced(TreeNode* root) 
    {
        if(root == nullptr)
            return true;

        //从根节点开始判断 是否平衡，再递归到每个节点 
        int height_diff = abs(tree_height(root->left) - tree_height(root->right));
        if(height_diff > 1)
            return false;
        else
            return isBalanced(root->left) && isBalanced(root->right);
    }

    //树高度
    int tree_height(TreeNode* node)
    {
        if(node == nullptr)
            return 0;
        
        return 1 + max(tree_height(node->left), tree_height(node->right));
    }


    //方法2、只要发现有不满足平衡条件的子树 直接返回
    bool isBalanced(TreeNode* root) 
    {
        return check_height(root) != -1;
    }

    //检查树高度 如果不平衡返回-1，平衡则返回高度
    int check_height(TreeNode* node)
    {
        if(node == nullptr)
            return 0;

        int left_height = check_height(node->left);
        if(left_height == -1)
            return -1;

        int right_height = check_height(node->right);
        if(right_height == -1)
            return -1;
        
        int height_diff = abs(left_height - right_height);
        if(height_diff > 1)
            return -1;
        else
            return 1 + max(left_height, right_height);
    }
};
```