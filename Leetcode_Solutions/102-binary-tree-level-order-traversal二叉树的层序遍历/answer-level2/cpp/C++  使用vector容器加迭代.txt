```
class Solution {
public:
    vector<vector<int>>result;
    void fun(vector<vector<int>>&result,vector<TreeNode*> Node){
        vector<int>temp_int;
        vector<TreeNode*>temp_tree;
        /**
        //这种做法 回导致顺序问题
        while(Node.size()!=0){
            TreeNode*node=Node.back();
            temp_int.push_back(node->val);
            if(node->left!=NULL)
                temp_tree.push_back(node->left);
            if(node->right!=NULL)
                temp_tree.push_back(node->right);
            Node.pop_back();
        }
        */
        for(int i=0;i<Node.size();i++){
            temp_int.push_back(Node[i]->val);
            if(Node[i]->left!=NULL)
                temp_tree.push_back(Node[i]->left);
            if(Node[i]->right!=NULL)
                temp_tree.push_back(Node[i]->right);
        }
        result.push_back(temp_int);
        if(temp_tree.size()!=0)
            fun(result,temp_tree);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return result;
        else{
            vector<TreeNode*>temp;
            temp.push_back(root);
            fun(result,temp);   
        }
        return result;
    }
};
```
