使用vector<vector<int>>* output 指针时，总会出现莫名其妙的错误，可以考虑将其设为全局变量来使用 
```
vector<vector<int>>output ;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        output.clear();
        if(root == NULL)return output;
        helper(0,root);
        return output;
        
    }
    void helper(int level,TreeNode* root){
        vector<int>temp;
        if(output.size()==level) output.push_back(temp);
        output[level].push_back(root->val);
        if(root->left) helper(level + 1, root->left );
        if(root->right) helper(level+ 1, root->right);
    }
};
```
