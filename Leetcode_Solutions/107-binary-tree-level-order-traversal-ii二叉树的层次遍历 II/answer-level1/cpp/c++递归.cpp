### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int dep = BTreeDepth(root);
        vector<vector<int>> res1(dep, vector<int>(0));
        this->res = res1;
        backTrack(root, dep-1);
        return res;
    }
    int BTreeDepth(TreeNode* root){
        return root == NULL ? 0 : max(BTreeDepth(root->left), BTreeDepth( root->right )) + 1;
    }
    void backTrack(TreeNode* root, int n){
        if(root){
            backTrack(root->left, n-1);
            backTrack(root->right, n-1);
            res[n].push_back(root->val);
        }
    }
};
```