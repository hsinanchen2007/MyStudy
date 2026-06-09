```
class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> stk;
        vector<int> ret;
        Node* n = NULL;
        if(root != NULL)
            stk.push(root);
        while(!stk.empty())
        {
            n = stk.top();
            stk.pop();
            ret.push_back(n->val);
            for(auto iter = n->children.rbegin(); iter != n->children.rend(); iter++)
            {
                stk.push(*iter);
            }
        }
        return ret;
    }
};
```
