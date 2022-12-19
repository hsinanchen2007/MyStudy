解法一：递归：
```
class Solution {
public:
    void dfs(TreeNode* root,vector<int>&ans){
        if(root==NULL)return;
        ans.push_back(root->val);
        dfs(root->left,ans);
        dfs(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        dfs(root,ans);
        return ans;
    }
};
```
解法二：非递归：

```
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>res;
        auto rt=root;
        while(!res.empty()||rt){
            while(rt){
                ans.push_back(rt->val);
                res.push(rt);
                rt=rt->left;
            }
            if(!res.empty()){
                rt=res.top();
                res.pop();
                rt=rt->right;
            }
        }
        return ans;
    }
};
```

