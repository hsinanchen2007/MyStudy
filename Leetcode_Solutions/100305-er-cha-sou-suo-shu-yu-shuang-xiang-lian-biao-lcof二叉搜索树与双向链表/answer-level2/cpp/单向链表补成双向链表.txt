### 解题思路
按照题目描述，我们中序遍历的结果，写成一个单向链表（只有next的那种），完成中序后，再回过头把前驱给补上。这样难度就大大降低了。需要注意的是这题需要设置一个头节点，这样对整体操作而言更为方便。
当然也可以在中序遍历过程中把前驱就写上（这样更快，但是头尾节点不好处理）。

### 代码

```cpp
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
Node *head=new Node(-65535);
Node *p=head;
void midorder(Node* root){
    if(root==NULL) return;
    midorder(root->left);
    Node *q=new Node(root->val);
    p->right=q;
    p=p->right;
    midorder(root->right);
}
    Node* treeToDoublyList(Node* root) {
        if(root==NULL) return NULL;
        midorder(root);
        p=head->right;
        while(p->right!=NULL){
            Node *q=p->right;
            q->left=p;
            p=p->right;
        }
        p->right=head->right;
        head->right->left=p;
        return head->right;
    }
};
```