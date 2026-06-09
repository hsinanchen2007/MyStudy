### 解题思路
每次先将 root的左节点next=root右节点， root右节点->next=root->next的左节点
若root没有next则将其右节点置为null
### 代码

```cpp
class Solution {
public:
    int flag = 1; 
    Node* connect(Node* root) {
        if(!root)return nullptr;
        if(flag){  // 将根节点next置为null
            root->next = nullptr;
            flag = 0;
        } 
        if(!root->left) return root;
        root->left->next = root->right;
        if(root->next)root->right->next = root->next->left;
        else root->right->next = nullptr;
        connect(root->left);
        connect(root->right);
        return root;
    }
};
```