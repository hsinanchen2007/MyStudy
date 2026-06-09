And using a stack called nodes to record the single branch nodes which are from root to one leaf 


```
if(!root) return false;
        stack<TreeNode*> stc;//right sub tree 
        stack<TreeNode*> nodes;// current treenodes of a branch
        TreeNode*p=root;
        TreeNode*pre=nullptr;
        int temp=0;
        while(true)//preorder-traversal
        {
            while(p)
            {
                temp+=p->val;
                stc.push(p->right);
                nodes.push(p);
                pre=p;
                p=p->left; 
            }
            if (temp==sum&&!pre->left&&!pre->right) return true;//is pre a leaf node?
            if(stc.empty()) break;
             while(true)
            {
                if(nodes.top()->right!=stc.top())// find the root of right subtree root in stc
                {
                    temp-=nodes.top()->val;//delete nodes of left branch
                    nodes.pop();
                }
                else
                    break;
                
            }//nodes->right=stc.top();
            p=stc.top();
            stc.pop(); 
        }
        
        return false;
```