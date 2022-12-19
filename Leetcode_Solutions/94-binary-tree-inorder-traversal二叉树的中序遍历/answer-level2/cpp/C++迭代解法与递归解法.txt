迭代法（效率更高，实测4ms）
```c++ []
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode> s;
        vector<int> ans;
        TreeNode* t = root;
        while(t || !s.empty()){
            while(t){  //遍历到最左边的叶结点
                s.push(*t);
                t = t->left;
            }
            if(!s.empty()){
                ans.push_back(s.top().val);
                t = s.top().right;
                s.pop();
            }
        }
        return ans;
    }
};
```
递归法（8ms）
```c++ []
class Solution {
    vector<int> ans;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root) {
            inorderTraversal(root->left);
            ans.push_back(root->val);
            inorderTraversal(root->right);
        }
        return ans;
    }
};
```
