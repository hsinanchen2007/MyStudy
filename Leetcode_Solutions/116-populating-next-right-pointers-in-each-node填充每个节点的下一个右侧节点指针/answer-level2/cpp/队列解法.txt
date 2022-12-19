    Node* connect(Node* root) {
        if(root==nullptr){
            return root;
        }
        Node* current;
        queue<Node*> q;
        int i,k;
        q.push(root);
        for(i=1;!q.empty();i*=2){
            for(k=0;k<i&&!q.empty();k++){
                current=q.front();
                if(current->left!=nullptr){
                    q.push(current->left);
                }
                if(current->right!=nullptr){
                    q.push(current->right);
                }
                q.pop();
                if(k<i-1){
                    current->next=q.front();
                }
                else{
                    current->next=nullptr;
                }
            }
        }
        return root;
    }