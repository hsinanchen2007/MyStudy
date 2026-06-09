### 解题思路
从根结点开始，如果左孩子非空，将左孩子的值赋值为（root->left->val += root->val * 10 ），然后递归递归左孩子，并将返回值赋值给sumLeft。同理对右孩子做同样的处理。最后如果该结点不是叶子结点，则返回值为sumLeft+sumRight；否则返回该结点的值val。

执行用时 :0 ms, 在所有 c 提交中击败了100.00% 的用户
内存消耗 :7.4 MB, 在所有 c 提交中击败了100.00%的用户

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sumNumbers(struct TreeNode* root){
    if(root == NULL)
        return 0;
    int sumLeft=0,sumRight=0;
    if(root->left != NULL)
    {
        root->left->val = root->val*10 + root->left->val;
        sumLeft=sumNumbers(root->left);
    }
    if(root->right != NULL)
    {
        root->right->val = root->val*10 + root->right->val;
        sumRight = sumNumbers(root->right);
    }
    if(root->left == NULL && root->right == NULL)
        return root->val;
    else
        return sumLeft+sumRight;
}
```