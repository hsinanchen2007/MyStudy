c++ 0ms and java 2ms点我查看详情
```
//c++
class Solution {
public:
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }
    
    void dfs(TreeNode* root, int i){
        if (root == NULL) return;
        if (ans.size() < i) ans.push_back(root->val);
        dfs(root->right, i+1);
        dfs(root->left, i+1);
    }
};

//java
class Solution {
    List<Integer> ans = new ArrayList();
    public List<Integer> rightSideView(TreeNode root) {
        dfs(root, 1);
        return ans;
    }
    
    void dfs(TreeNode root, int i){
        if (root == null) return;
        if (ans.size() < i) ans.add(root.val);
        dfs(root.right, i+1);
        dfs(root.left, i+1);
    }
}
```