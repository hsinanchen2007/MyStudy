### 解题思路
欢迎讨论。

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
//-------------------------------递归
class Solution {
public:

    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        sum = sum - (root->val);
        if(!root->left&&!root->right)
        {
            if(sum==0) return true;
            else return false;
        }
        return hasPathSum(root->left,sum)|| hasPathSum(root->right,sum);  
    }
};
//-------------------------------迭代
class Solution {
public:

    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        stack<pair<TreeNode*,int>> st;
        st.push(make_pair(root,sum-root->val));
        while(!st.empty())
        {
            TreeNode* tp = st.top().first;
            int ts = st.top().second;
            st.pop();
            if(!tp->left && !tp->right && ts==0) return true;
            if(tp->left)
            {
                st.push(make_pair(tp->left,ts-tp->left->val));
            }
            if(tp->right)
            {
                st.push(make_pair(tp->right,ts-tp->right->val));
            }
        }
        return false;
    }
};
```