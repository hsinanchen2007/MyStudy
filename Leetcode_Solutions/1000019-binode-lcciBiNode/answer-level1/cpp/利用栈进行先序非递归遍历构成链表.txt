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
    TreeNode* convertBiNode(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *p=root,*res,*temp;
        res=new TreeNode(-1);
        res->left=NULL;
        temp=res;
        while(p||!st.empty())
        {
            if(p)
            {
                st.push(p);
                p=p->left;
            }
            else
            {
                p=st.top();
                st.pop();

                TreeNode *t=new TreeNode(p->val);
                t->left=NULL;
                temp->right=t;
                temp=t;
                
                p=p->right;
            }
        }
       res=res->right;
       return res; 
    }
};
```