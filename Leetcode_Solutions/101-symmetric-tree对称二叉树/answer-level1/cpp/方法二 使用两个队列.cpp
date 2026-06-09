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
        if(NULL == root){return true;}
        queue<TreeNode*> s1;
        queue<TreeNode*> s2;
        s1.push(root->left);
        s2.push(root->right);
        while(!s1.empty() &&!s2.empty())
        {
            TreeNode*  p = s1.front();
            s1.pop();
            TreeNode*  q = s2.front();
            s2.pop();
            if(NULL == p && NULL == q)
            {
                continue;//这里要是continue,而不是return，必须全部遍历或者找到不对的
            }
            else if((NULL == p && NULL != q)||(NULL != p && NULL == q))
            {
                return false;
            }
            if(p->val == q->val)
            {
                s1.push(p->left);
                s1.push(p->right);
                s2.push(q->right);
                s2.push(q->left);
            }
            else
            {
                return false;
            }
        }
        if((s1.empty() && !s2.empty()) || (s2.empty() && !s1.empty()))
        {
            return false;
        }
        return true;


        
    }
};
```