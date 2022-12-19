```
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int width = q.size();
            Node* temp = q.front();
            q.pop();
            for(int i=1;i<width;i++){
                temp->next = q.front();//指向右侧结点
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                temp = q.front();
                q.pop();
            }
            //到最右侧了，把next指针指向null
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            temp->next = NULL;
        }
        return root;
    }
};
```
