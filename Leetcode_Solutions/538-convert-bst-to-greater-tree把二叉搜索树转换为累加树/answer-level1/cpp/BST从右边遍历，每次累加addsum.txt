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
    TreeNode* convertBST(TreeNode* root) {
        int addsum=0;
        int temp;
        stack<TreeNode*> st;
        TreeNode *p=root;
        while(p||!st.empty())
        {
            if(p)
            {
                st.push(p);
                p=p->right;
            }
            else
            {
                p=st.top();
                st.pop();
                temp=p->val;
                p->val+=addsum;
                addsum+=temp;
                p=p->left;
            }
        }
        return root;
    }
};
```