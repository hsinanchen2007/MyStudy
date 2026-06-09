
```
执行用时 :
16 ms, 在所有 cpp 提交中击败了99.47%的用户
内存消耗 :
19.1 MB, 在所有 cpp 提交中击败了100.00%的用户
```

```
class Solution {
private:
    void p(Node *root){
        if(!root)   return;
        Node *temp = root;
        int cnt = 1;
        while(root && (root->left)){
            if(root->left && cnt%2)
                root->left->next = root->right;
            else if(root->next)
                root->right->next = root->next->left;
            cnt++;  
            if(cnt%2)
                root = root->next;
        }
        if(temp->left)  p(temp->left);
        return;
    }
public:
    Node* connect(Node* root) {
        if(!root)   return root;
        Node *temp = root;
        p(temp);
        return root;
    }
};
```
