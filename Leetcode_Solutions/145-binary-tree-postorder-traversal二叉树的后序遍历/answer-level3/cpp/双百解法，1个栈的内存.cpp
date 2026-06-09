### 解题思路
![1.png](https://pic.leetcode-cn.com/c80bea1af834ee9948a5dcb45f890f1c6a39dc30ece150f5cf56b8cb38362168-1.png)

- 每次遇到叶结点即输出
- 非叶结点将孩子结点加入栈后，将其改为叶结点（哈哈作弊解法）

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if(root)    st.push(root);
        while(!st.empty()){
            root=st.top();
            if(root->right)  st.push(root->right);
            if(root->left)  st.push(root->left);
            if(!root->left && !root->right){
                ans.push_back(root->val);
                st.pop();
            }
            root->left=root->right=NULL;
        }
        return ans;
    }
};
```