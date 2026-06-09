
```
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        
        Node* f=root->left;
        root->next=NULL;
        Node* cur=root;
        while(f!=NULL||cur!=NULL){
            if(cur->left!=NULL)cur->left->next=cur->right;
            if(cur->right!=NULL)cur->right->next=(NULL==cur->next)?NULL:cur->next->left;
            
            cur=cur->next;
            if(cur==NULL){
                cur=f;
                if(cur!=NULL)
                    f=cur->left;
                else
                    return root;
            }
        }
        return root;
    }
};
```
