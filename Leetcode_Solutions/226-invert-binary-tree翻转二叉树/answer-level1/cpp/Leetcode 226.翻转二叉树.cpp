### 解题思路
DFS前中后 + BFS

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
    TreeNode* invertTree(TreeNode* root)
    {
        if(!root)   return root;
        queue<TreeNode* > q;
        q.push(root);
        TreeNode *cur;
        while(!q.empty())
        {
            cur = q.front();
            q.pop();
            swap(cur->left, cur->right);

            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        return root;
    }

     TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;
        //前序遍历
        //交换操作
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        invertTree(root->left);
        invertTree(root->right);
        return root; 
        
        
        //中序遍历  左右子树提前交换过，所以遍历右子树的时候实际为遍历左子树
        invertTree(root->left);
        //交换操作
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        return root; 
        

        //后续遍历
        invertTree(root->left);
        invertTree(root->right);
        //交换操作
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root; 

    }
};
```