### 解题思路

通过创建两个栈交替存储

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        vector<vector<int>> ans;
        if(root != NULL)
            st1.push(root);
        while( (!st1.empty()) || (!st2.empty())  ){
            vector<int> temp1;
            vector<int> temp2;
            
            while(!st1.empty()){
                TreeNode *a = st1.top();
                st1.pop();
                if(a->left != NULL)
                    st2.push(a->left);
                if(a->right != NULL)
                    st2.push(a->right);
                temp1.push_back(a->val);
            }
            if(!temp1.empty())
                ans.push_back(temp1);
            
            while(!st2.empty()){
                TreeNode *a = st2.top();
                st2.pop();
                if(a->right != NULL)
                    st1.push(a->right);
                if(a->left != NULL)
                    st1.push(a->left);
                temp2.push_back(a->val);
            }
            if(!temp2.empty())
                ans.push_back(temp2);
        }
        return ans;
    }
};
```