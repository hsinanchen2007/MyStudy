递归后序遍历二叉树，当左右子树都为二叉搜索树时判断当前子树是否满足二叉搜索树。如果满足，则计算当前子树的节点之和并更新最大子树和，然后把子树和返回到父节点的遍历。

需要注意的是，叶子节点也是满足二叉搜索子树。因此当遍历到空节点时返回 true。

时间复杂度 O(n)，空间复杂度 O(logn)。

* 示例 :

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
private:
    int max_sum;

public:
    bool process(TreeNode* root, int& sum)
    {
        if (root == NULL)
        {
            return true;
        }

        int left_sum = 0;
        bool ret_left = process(root->left, left_sum);
        int right_sum = 0;
        bool ret_right = process(root->right, right_sum);

        if ((ret_left && ret_right) &&
            ((root->left == NULL) || (root->left->val < root->val)) &&
            ((root->right == NULL) || (root->right->val > root->val)))
        {
            sum = left_sum + right_sum + root->val;
            max_sum = std::max(max_sum, sum);

            return true;
        }
        else
        {
            return false;
        }
    }

    int maxSumBST(TreeNode* root) 
    {
        max_sum = 0; 

        int sum = 0;
        process(root, sum);

        return max_sum;
    }
};
```
