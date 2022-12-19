### 解题思路
相对于递归效率较高
![image.png](https://pic.leetcode-cn.com/b981a8a6a831024df28f873aa573ad151370d9ffc329ce9742979c23b1f03e2c-image.png)


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
    vector<int> preorderTraversal(TreeNode* root) {
     vector<int> ret;
     stack<TreeNode*> st;
     st.push(root);
     TreeNode* node;
     while(!st.empty())
     {
         node=st.top();
         st.pop();
         if(node==NULL) continue;
         ret.push_back(node->val);
         st.push(node->right);
         st.push(node->left);

     }
     return ret;
    }

};
```