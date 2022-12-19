### 解题思路
此处撰写解题思路

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
    bool isSymmetric(TreeNode* root) {
        //标志位
        bool flag=true;
        if(!root)
            return true;
        //将二叉树分为左子树、右子树
        queue<TreeNode* > left;
        queue<TreeNode* > right;
        //入队
        left.push(root->left);
        right.push(root->right);
        while(!left.empty()&&!right.empty())
        {
            //出队
            TreeNode* l=left.front();
            TreeNode* r=right.front();
            left.pop();
            right.pop();
            //左右都为空的时候，成立
            if(l==NULL&&r==NULL)
                continue;
            //左右不为空且值相等时，成立
            if(l!=NULL&&r!=NULL&&l->val==r->val)
            {
                //入队
                left.push(l->left);
                right.push(r->right);
                left.push(r->left);
                right.push(l->right);
            }
            else
            {
                //其余情况，不成立
                flag=false;
                break;
            }
        }
        return flag;
    }
};
```