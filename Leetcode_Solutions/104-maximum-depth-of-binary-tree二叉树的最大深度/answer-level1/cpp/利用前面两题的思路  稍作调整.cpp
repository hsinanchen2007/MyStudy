```
class Solution {
public:
    vector<vector<TreeNode*>>result;
    void fun(vector<vector<TreeNode*>>& result,vector<TreeNode*>temp){
        vector<TreeNode*>tp;
        if(temp.size()!=0)
            result.push_back(temp);
        for(int i=0;i<temp.size();i++){
            if(temp[i]->left!=NULL)
                tp.push_back(temp[i]->left);
            if(temp[i]->right!=NULL)
                tp.push_back(temp[i]->right);
        }
        if(tp.size()!=0)
            fun(result,tp);
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        else{
            vector<TreeNode*>temp;
            temp.push_back(root);
            fun(result,temp);
                      
        }
         return result.size();
    }
};
```
比较占用内存
