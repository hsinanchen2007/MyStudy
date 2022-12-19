相比于中序线索二叉树的创建，递归主体只需要改两个条件。
```
class Solution {
public:
    void InTread(Node *p,Node *&pre){ //注意p不要用引用，递归的时候，每一层一个p
        if(p){
            InTread(p->left,pre);
            if(p->left!=pre)   //修改条件
                p->left=pre;
            if(pre&&pre->right!=p) //修改条件
                pre->right=p;
            pre=p;
            InTread(p->right,pre);
        }
    }
    Node* treeToDoublyList(Node* root) {
       if(root==NULL)
            return root;
        Node *head=new Node(1);
        Node *pre=head;
        InTread(root,pre);
        head->right->left=pre;
        pre->right=head->right;
        pre=head->right;
        return pre;
    }
};
```
