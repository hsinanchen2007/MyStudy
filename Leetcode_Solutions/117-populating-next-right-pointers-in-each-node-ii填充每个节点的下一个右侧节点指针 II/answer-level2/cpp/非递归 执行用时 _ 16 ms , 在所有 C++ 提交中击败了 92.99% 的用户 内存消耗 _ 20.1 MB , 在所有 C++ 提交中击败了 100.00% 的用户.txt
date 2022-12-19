```
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
        Node* p = NULL;
        Node* q = NULL;
        if(root->left != NULL){
            root->left->next = root->right;
            p = root->left;
            if(p->left == NULL && p->right != NULL)
                q = p->right;
            else if(p->left != NULL)
                q = p->left;
            else
                connect(root->right);
        }
        else
            connect(root->right);
        Node* temp;
        while(q != NULL){
            while(p != NULL){
                if(p->left != NULL)
                    p->left->next = p->right;
                if(p->next != NULL){
                    if(p->right != NULL)
                        temp = p->right;
                    else if(p->left != NULL)
                        temp = p->left;
                    else{
                        p = p->next;
                        continue;
                    }
                    while(p->next != NULL && p->next->left == NULL && p->next->right == NULL)
                        p = p->next;
                    if(p->next != NULL && p->next->left == NULL && p->next->right != NULL)
                        temp->next = p->next->right;
                    else if(p->next != NULL && p->next->left != NULL)
                        temp->next = p->next->left;
                }
                p = p->next;
            }
            p = q;
            temp = p;
            while(temp != NULL && temp->left == NULL && temp->right == NULL)
                temp = temp->next;
            if(temp != NULL && temp->left != NULL)
                q = temp->left;
            else if(temp != NULL && temp->right != NULL)
                q = temp->right;
            else
                q = NULL;
        }
        return root;
    }
};
```
