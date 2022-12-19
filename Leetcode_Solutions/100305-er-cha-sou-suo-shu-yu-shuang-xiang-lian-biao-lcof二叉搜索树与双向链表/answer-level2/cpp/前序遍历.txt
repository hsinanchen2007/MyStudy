### 解题思路
前序遍历
遍历子树时返回修改后子树的头和尾
最后修改头和尾的left和right数据成员形成环形链表
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
    Node* treeToDoublyList(Node* root) {
        if(root==nullptr)
            return nullptr;
        Node* head;
        Node* rear;
        BuildList(root,head,rear);
        head->left=rear;
        rear->right=head;
        return head;
    }
    void BuildList(Node* node,Node* &head,Node* &rear){
        head=node;
        Node* rechead;
        if(node->left!=nullptr){
            BuildList(node->left,head,rear);
            rear->right=node;
            node->left=rear;
        }
        rechead=head;
        rear=node;
        if(node->right!=nullptr){
            BuildList(node->right,head,rear);
            node->right=head;
            head->left=node;
        }
        head=rechead;
        return;
    }
};
```