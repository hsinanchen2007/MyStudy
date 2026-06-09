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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool flag = true;
        helper(p, q, flag);

        return flag;        
    }

    void helper(TreeNode* p, TreeNode* q, bool &flag)
    {
        if(p!=NULL && q!=NULL)
        {
            helper(p->left, q->left, flag);

            if(p->val != q->val)
            {
                flag = false;
                return;
            }
            
            helper(p->right, q->right, flag);
        }
        else if(p==NULL && q==NULL)
        {
            return;
        }
        else
        {
            flag = false;
            return;
        }
    }
};
```