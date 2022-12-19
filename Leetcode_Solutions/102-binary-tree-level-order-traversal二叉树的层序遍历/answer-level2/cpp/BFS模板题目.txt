class Solution {

public:
    //
    vector<vector<int>> levelOrder(TreeNode* root)
     {
        vector<vector<int>>res;
        //BFS 模板题目 
        if(root==NULL)  return{} ;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode * p=NULL;    //初始化为空  也可在循环内部建立临时指针
        while(!q.empty())
        {   
            vector<int> temp;
            int s=q.size();
            for(int i=0;i<s;++i)
            {   
                p=q.front();
                q.pop();
                temp.push_back(p->val);
                if(p->left!=NULL)  q.push(p->left);
                if(p->right!=NULL)  q.push(p->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};
```
