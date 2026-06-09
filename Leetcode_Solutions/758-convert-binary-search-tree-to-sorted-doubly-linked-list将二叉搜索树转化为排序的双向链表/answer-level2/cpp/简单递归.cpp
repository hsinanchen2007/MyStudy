### 解题思路
简单递归，还比较高效。刚开始忽略了一点就是传入的指针也可以作为头或者尾再传出去的。
整体就是进入一个子树将头尾节点传出来，对头尾节点进行相应连接，或者继续传给上一层
### 代码

```cpp

class Solution {
public:
    void todo(Node* root,Node*&head,Node*&rear){
    if(root->left==nullptr){
        head=root;
    }
    else{
        Node*r;
        todo(root->left,head,r);
        r->right=root;
        root->left=r;
    }
    if(root->right==nullptr){
        rear=root;
    }
    else{
        Node*h;
        todo(root->right,h,rear);
        h->left=root;
        root->right=h;
    }
}
    Node* treeToDoublyList(Node* root) 
    {
        if(root==nullptr)
            return root;
        Node*head,*rear;
        todo(root,head,rear);
        head->left=rear;
        rear->right=head;
        return head;
    }
};
```