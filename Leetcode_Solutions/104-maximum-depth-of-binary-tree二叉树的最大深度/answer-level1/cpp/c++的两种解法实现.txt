方法1：递归
```
    int MaxDepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left_depth = MaxDepth(root->left);
        int right_depth = MaxDepth(root->right);
        return left_depth>right_depth ? left_depth+1 : right_depth+1;
    }
```

方法２：队列遍历
```
    int MaxDepth(TreeNode* root){
        std::queue<std::pair<TreeNode*, int> > node_queue;
        if(root!=NULL){
            node_queue.push(std::pair<TreeNode*, int>(root, 1));
        }

        int depth = 0;
        while(!node_queue.empty()){
            std::pair<TreeNode*, int> current = node_queue.front();
            node_queue.pop();

            auto current_root = current.first;
            auto current_depth = current.second;

            depth = current_depth>depth ? current_depth : depth;
            if(current_root->left){
                node_queue.push(std::pair<TreeNode*, int>(current_root->left, current_depth+1));
            }
            if(current_root->right){
                node_queue.push((std::pair<TreeNode*, int>(current_root->right, current_depth+1)));
            }
        }

        return depth;
    }
```
