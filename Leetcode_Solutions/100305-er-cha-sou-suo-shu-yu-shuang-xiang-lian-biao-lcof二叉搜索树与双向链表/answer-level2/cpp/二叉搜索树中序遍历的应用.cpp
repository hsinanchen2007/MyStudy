对于一个二叉搜索树，其中序遍历的结果是从小到大排序的
与常规的中序遍历不同的是，我们在访问到根节点时需要将左右子树与根节点连接起来

设当前结点root的前一个结点为pre，那么访问到当前结点时，需要
root—>left=pre;
pre->right=root;
即完成双向链表
需要注意的是头节点的位置，为最左边的结点，即二叉搜索树中序遍历访问到的第一个结点，在这个结点的位置对head和pre进行初始化

最后pre会指向最后一个结点，将其与头节点相连即完成循环双向链表。

```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        Node *pre=nullptr;
        Node *head=nullptr;

        inorder(root,pre,head);
        head->left=pre;
        pre->right=head;

        return head;
    }

    void inorder(Node *root,Node *&pre,Node *&head)
    {
        if(!root) return;
        inorder(root->left,pre,head);
        if(!head)
        {
            head=root;
            pre=root;
        }else
        {
            pre->right=root;
            root->left=pre;
            pre=root;
        }
        inorder(root->right,pre,head);

    }
};
```
