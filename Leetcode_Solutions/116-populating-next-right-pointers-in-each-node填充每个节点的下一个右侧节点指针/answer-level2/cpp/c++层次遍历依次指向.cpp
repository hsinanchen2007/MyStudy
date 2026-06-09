### 代码

```cpp
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            int len = que.size();
            for(int i = 0; i < len; i++){
                Node* node = que.front();
                que.pop();
                if(i < len-1) node->next = que.front();
                if(node->left){
                    que.push(node->left);
                    que.push(node->right);
                }
            }
        }
        return root;
    }
};
```