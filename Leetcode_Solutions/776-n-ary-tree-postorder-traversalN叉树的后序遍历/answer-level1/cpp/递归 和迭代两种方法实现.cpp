
# 迭代

```
class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root==0)return {};
        stack<Node* >st;
        vector<int>res;
        while(root)
        {
            if((root->children).size()>=1)
            {
                st.push(root);
                for(auto it=(root->children).rbegin();it!=(root->children).rend()-1;++it)
                {
                    st.push(*it);
                }
                
                root=(root->children)[0];
            }
            else
            {
                res.push_back(root->val);
                while(!st.empty())
                {
                   if(!(st.top()->children).empty()&&(st.top()->children).back()==root)
                   {  root=st.top();
                    res.push_back(root->val);
                    st.pop();
                   }
                    else
                    {
                         root=st.top();
                         st.pop();
                         break;
                    }
                }
                if(st.empty())return res;
            }  
            
        }
        return res;
    }
};
```
# 递归
```
class Solution {
public:
    vector<int> postorder(Node* root) {
       
        travl(root); 
        return res;
        
    }
    
    void travl(Node* root)
    {
        if(root==0)return;
        for(auto c:root->children)
        {
            travl(c);
        }
        res.push_back(root->val);
    }
    vector<int>res;
};
```
