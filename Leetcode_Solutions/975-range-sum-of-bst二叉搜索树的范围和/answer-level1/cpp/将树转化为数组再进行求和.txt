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
    int rangeSumBST(TreeNode* root, int L, int R) {
        vector<int> res;
        int sum=0;
        stack<TreeNode*> st;
        TreeNode *p=root;
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
                res.push_back(p->val);
                p=p->right;
            }
        }
        vector<int>::iterator left=lower_bound(res.begin(),res.end(),L);
        vector<int>::iterator right=lower_bound(res.begin(),res.end(),R);
        for(;left!=right;left++)
            sum+=*left;
        sum+=*left;
        return sum;
    }
};
```