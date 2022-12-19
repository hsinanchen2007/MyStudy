这一类题都是用层次序遍历，先申请一个队列，存入根节点，每一遍循环一层，将这一层清空，录入该层的孩子节点，返回下层size,万变不离其宗，层次遍历框架记住就没有问题

```
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        queue<Node*> q{{root}};
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* t=q.front();
                q.pop();
                if(i!=n-1){
                    Node* tNext=q.front();
                    t->next=tNext;
                }
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
        }
        return root;
    }
};
```
