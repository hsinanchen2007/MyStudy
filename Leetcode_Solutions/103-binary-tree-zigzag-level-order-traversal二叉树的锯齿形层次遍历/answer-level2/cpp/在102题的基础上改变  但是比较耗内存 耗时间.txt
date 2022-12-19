```
class Solution {
public:
    vector<vector<int>>result;
    void fun(vector<vector<int>>&result,vector<TreeNode*> Node,bool flag){
        vector<int>temp_int;
        vector<TreeNode*>temp_tree;
        if(flag){
        for(int i=0;i<Node.size();i++){
            temp_int.push_back(Node[i]->val);
            if(Node[i]->left!=NULL)
                temp_tree.push_back(Node[i]->left);
            if(Node[i]->right!=NULL)
                temp_tree.push_back(Node[i]->right);
        }
    }else{
             for(int i=Node.size()-1;i>-1;i--){
            temp_int.push_back(Node[i]->val);
                 if(Node[i]->right!=NULL)
                temp_tree.insert(temp_tree.begin(),Node[i]->right);
            if(Node[i]->left!=NULL)
                temp_tree.insert(temp_tree.begin(),Node[i]->left);
                 }
        }
        result.push_back(temp_int);
        if(temp_tree.size()!=0)
            fun(result,temp_tree,!flag);
    }
    vector<vector<int>>  zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return result;
        else{
            vector<TreeNode*>temp;
            temp.push_back(root);
            fun(result,temp,true);   
        }
        return result;
    }
};
```
