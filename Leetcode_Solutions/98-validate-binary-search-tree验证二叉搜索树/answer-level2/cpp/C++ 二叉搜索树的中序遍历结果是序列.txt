代码如下：
```
代码块
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        //vector<int> t;
        dfs(root);
        for(int i =0;i < t.size() - 1;i++){
            if(t[i + 1] <= t[i]) return false;
        }
        return true;

    }   

    void dfs(TreeNode* root){
        if(root -> left) dfs(root->left);
        t.push_back(root -> val);
        if(root -> right) dfs(root->right);
    }
private:
    vector<int> t;
};
```
