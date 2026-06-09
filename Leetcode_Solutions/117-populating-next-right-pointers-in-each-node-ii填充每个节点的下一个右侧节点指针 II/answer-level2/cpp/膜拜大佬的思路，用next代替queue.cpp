
膜拜大佬的思路：
队列是为了维护先后关系
但是先后关系本来就存在了next里
所以可以不使用队列

队列做法
```gradle
Node* connect(Node* root) {
        if(root == NULL)return root;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node*cur = NULL;
            int size = q.size();
            for(int i = size;i>=0;i--){
                Node *tmp = q.front();q.pop();
                if(cur != NULL){
                    cur->next = tmp;
                }
                cur = tmp;
                if(tmp->left)q.push(tmp->left);
                if(tmp->right)q.push(tmp->right);
            }
        }
        return root;
```
使用next来代替队列
```xl
Node* connect(Node* root) {
        Node *last = root;
        while(last != NULL){
            // 获得队首元素
            while(last && last->left == NULL && last->right == NULL)last = last->next;
            if(last == NULL)break;
            Node *cur = NULL;
            // 遍历队列
            for(Node *i = last;i != NULL;i = i->next){
                // 进行push和pop操作
                if(i -> left){
                    if(cur != NULL){
                        cur->next = i->left;
                    }
                    cur = i->left;
                }
                if(i -> right){
                    if(cur != NULL){
                        cur->next = i->right;
                    }
                    cur = i->right;
                }
            }
            // 更新队首
            last = last->left ? last->left : last->right;
        }
        return root;
    }
```


执行用时 : 592 ms, 在Populating Next Right Pointers in Each Node II的C++提交中击败了91.04% 的用户
内存消耗 : 66.4 MB, 在Populating Next Right Pointers in Each Node II的C++提交中击败了94.59% 的用户