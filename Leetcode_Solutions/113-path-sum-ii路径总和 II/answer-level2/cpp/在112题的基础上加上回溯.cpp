代码比较简洁   就是在112题的基础上加上了两个vector容器
```
class Solution {
public:
    vector<vector<int>>result;
    vector<int>temp;
    void fun(TreeNode*root,vector<int>&temp,int sum){
        if(root==NULL);
        else{
            temp.push_back(root->val);
            if(root->val==sum&&root->left==NULL&&root->right==NULL)
                result.push_back(temp);
            else{
                fun(root->left,temp,sum-root->val);
                fun(root->right,temp,sum-root->val);
                
            }
          temp.pop_back();  //回溯
        }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        if(root==NULL)
            return  result;
        else
            fun(root,temp,sum);
        return result;
    }
};
```
