首先用中序遍历将所有结点存起来（递归写法的），后面遍历存起来的结点更改指针就好了。
```
class Solution {
public:
    vector<Node *> q;
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return root;
        qianxu(root);
        Node *p = *(q.begin());
        for(auto i =q.begin()+1;i!=q.end();i++){
            p->right = (*i);
            (*i)->left = p;
            p = (*i); 
        }
        p = *(q.begin());
        Node *pend = *(q.end()-1);
        pend->right = p;
        p->left = pend;
        return p;
    }
    void qianxu(Node* node){
        if(node->left!=NULL){
            qianxu(node->left);
        }
        q.push_back(node);
        if(node->right!=NULL){
            qianxu(node->right);
        }
        return ;
    }
};
```
