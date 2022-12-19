### 解题思路
注意判断空指针

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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL && sum == 0)
        return false;
        search(root, 0, sum);
        return flag;
    }
    void search(TreeNode* node, int num, int sum)
    {
        if(node != NULL && node->left == NULL && node->right == NULL)
        {
            if(num + node->val == sum)
                flag = true;
            return ;
        }
        if(node != NULL && node->left != NULL)
        search(node->left, node->val + num, sum);
        if(node != NULL && node->right != NULL)
        search(node->right, node->val + num, sum);
    }
private:
    bool flag = false;
};
```