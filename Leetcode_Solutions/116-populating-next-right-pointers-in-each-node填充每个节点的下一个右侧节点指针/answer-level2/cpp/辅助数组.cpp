```cpp
class Solution {
public:
    void helper(vector<Node*>&vec,Node*root,int h)
    {
        if(root==nullptr)return;
        if(h>vec.size()){
            root->next=nullptr;
            vec.push_back(root);
        }
        else {
            root->next=vec[h-1];
            vec[h-1]=root;
        }
        helper(vec,root->right,h+1);
        helper(vec,root->left,h+1);
    }
    Node* connect(Node* root) {
        vector<Node*>vec;
        helper(vec,root,1);
        return root;
    }
};
```