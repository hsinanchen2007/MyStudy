从根开始，每次串联当前节点的左右子节点。每行结束后，串联下一行，由于当前行已经串联过，所以下一行可以使用当前行的next寻找同层的节点。
```
class Solution {
public:
    Node* connect(Node* root) {
        for(Node *pre=root; pre; pre=pre->left){
            for(Node *cur=pre; cur; cur=cur->next){
                if(cur->left) cur->left->next=cur->right;
                if(cur->right && cur->next) cur->right->next=cur->next->left;
            }
        }
        return root;
    }
};
```
