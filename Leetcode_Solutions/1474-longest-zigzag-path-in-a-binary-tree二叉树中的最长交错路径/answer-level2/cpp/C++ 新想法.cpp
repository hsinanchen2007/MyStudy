这个想法也是我第一次写的，当时瞎写想出来的
主要就是底层节点向顶层发信号
```
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
    struct answer{
        int left;
        int right;
    };
    int my_max;
    struct answer visit(TreeNode* root)
    {
        answer temp;
        if(root->left==NULL)
        {
            temp.left=0;
        }
        else
        {
            answer temp1=visit(root->left);
            temp.left=temp1.right+1;
        }
        if(root->right==NULL)
        {
            temp.right=0;
        }
        else
        {
            answer temp3=visit(root->right);
            temp.right=temp3.left+1;
        }
        if(temp.left>my_max)
        {
            my_max=temp.left;
            
        }
        if(temp.right>my_max)
        {
            my_max=temp.right;
            
        }
        return temp;
        
    }
    int longestZigZag(TreeNode* root) {
        my_max=-1;
        answer temp4=visit(root);
        return my_max;
    }
};
```
