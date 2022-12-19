```
class Solution{
public:
    vector<int> postorder(Node* root){
        vector<int> res;
        if(!root) return res;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()){
            Node* node = s.top();
            if(node->children.size() == 0){
                res.push_back(node->val);
                s.pop();
            }else{
                for(int i = node->children.size() - 1; i >= 0; i--) s.push(node->children[i]);
                node->children.clear();
            }
        }
        return res;
    }
};
```
