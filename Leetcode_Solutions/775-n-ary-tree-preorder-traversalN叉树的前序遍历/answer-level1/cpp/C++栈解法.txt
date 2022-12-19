```
class Solution {
public:
    vector<int> preorder(Node* root) 
    {
        
        vector<int> ans;
        if(root==NULL) return ans;
        stack<Node*> s;
        s.push(root);
        Node* temp=NULL;
        int k=0;
        while(!s.empty())
        {
            temp=s.top();
            s.pop();
            ans.push_back(temp->val);
            k=temp->children.size();
            for(;k>0;k--)
            {
                s.push(temp->children[k-1]);
            }
        }
        return ans;
        
    }
};
```
