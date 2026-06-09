用一个队列实现bFS，遇到没有左右节点的叶子元素即返回其层值，维护一个count变量用来计算下一层有多少个节点，一旦该层节点全部遍历完，更新下一层节点数，层值加一。





```
class Solution {
public:
    int minDepth(TreeNode* root) {
        //bfs
        
        if(root==NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res=1;
        int count=q.size();
        while(!q.empty())
        {
            TreeNode* ptr=q.front();
            cout<<ptr->val<<endl;
            q.pop();
            count--;
            if(ptr->left==NULL&&ptr->right==NULL)
                return res;
                if(ptr->left!=NULL)
                q.push(ptr->left);
                if(ptr->right!=NULL)
                q.push(ptr->right);
            if(count==0)
            {
               count=q.size();
                ++res;
            }
                
        }
        return res;
    }
};
```
