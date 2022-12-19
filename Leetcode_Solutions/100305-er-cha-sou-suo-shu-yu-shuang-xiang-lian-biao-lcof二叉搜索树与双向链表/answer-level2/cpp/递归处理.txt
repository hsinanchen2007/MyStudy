申请一个头结点，之后中序遍历，最后头尾相连
```
class Solution {
public:
    Node* head=new Node(0);
    Node* pre=head;
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        else
        {
            treeToDoublyList(root->left);
            //在这里处理数据
            pre->right=root;
            root->left=pre;
            pre=root;
            treeToDoublyList(root->right);
        }
        //最后将尾结点和头节点相连
        pre->right=head->right;
        head->right->left=pre;
        return head->right;
    }
};
```
