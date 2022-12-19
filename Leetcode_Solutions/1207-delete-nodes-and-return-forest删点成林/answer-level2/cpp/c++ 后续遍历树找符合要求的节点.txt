首先用一个哈希表存储目标值
然后，后续遍历整棵树 当出现满足要求的节点时候先将他的左右子树放到一个vector中存储起来
再将此结点删除
最后遍历之前存储节点的vector若为空则不处理，不为空则放到一个新的vector中方便返回
```
class Solution {
public:
    vector<TreeNode*> res; 
    vector<TreeNode*> ans;
    map<int,int> p;
    void dfs(TreeNode* &root)   //这里传参数要是引用，不然对于节点的操作不会有什么实际性的改动
    {
        if(root==NULL)
            return ;
        dfs(root->left);
        dfs(root->right);
        if(p.find(root->val)!=p.end())
        {
            res.push_back(root->left);
            res.push_back(root->right);
            root=NULL;
            return ;
        }   
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
       
        if(root==NULL)
            return ans;
        for(auto ar:to_delete)
            p[ar]++;

        dfs(root);        
        res.push_back(root);
        int n=res.size();
        for(auto ar:res)
            if(ar!=NULL)
                ans.push_back(ar);
        return ans;
    }
};
```
