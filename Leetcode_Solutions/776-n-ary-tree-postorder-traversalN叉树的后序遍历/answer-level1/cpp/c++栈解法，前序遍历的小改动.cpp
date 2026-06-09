前序遍历是根、左、右
后序是左、右、根
所以我把前序遍历改成了根、右、左，然后再将结果逆置
属于前序遍历的小改动


```
class Solution {
public:
    vector<int> postorder(Node* root) 
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
            for(int i=0;i<k;i++)
            {
                s.push(temp->children[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```
