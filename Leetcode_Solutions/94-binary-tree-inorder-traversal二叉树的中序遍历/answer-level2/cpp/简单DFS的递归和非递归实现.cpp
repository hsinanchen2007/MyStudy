## 递归实现

```C++ []
class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans){
        if(root == NULL)
            return;
        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};
```
递归就很简单了，左中右，结束！

## 非递归实现
```C++ []
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* p = root;
        stack<TreeNode*> st;
        while(p || !st.empty()){
            while(p){
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            ans.push_back(p->val);
            p = p->right;
        }
        return ans;
    }
};
```
非递归的思路就是先要找到当前节点的最左子节点，然后放问它，路径间经过的左右节点都要推入栈中，然后将最左子节点出栈，访问，然后访问最左子节点的右节点。