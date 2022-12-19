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
    int ans;
    int maxdepth(TreeNode* rt){
        if(rt==NULL)return 0;
        int L=maxdepth(rt->left);
        int R=maxdepth(rt->right);
        ans = max(ans,L+R+1);
        return max(L,R)+1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        maxdepth(root);
        return ans-1;
        /*
        int ans = 0;
        if(root == NULL) return ans;
        std::stack<TreeNode*> s;
        s.push(root);
        TreeNode* cur;
        while(!s.empty())
        {
            cur = s.top();
            s.pop();
            if(cur->left)
               s.push(cur->left);
            if(cur->right)
               s.push(cur->right);
            

        }
        */
    }
};
```