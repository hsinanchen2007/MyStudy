```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root and (root->left or root->right)){
            if(root->left and root->right) root->left->next = root->right;
            
            Node *node = root->right ? root->right : root->left;
            Node *head = root->next;
            while (head and not (head->left or head->right)){
                head = head->next;
            }
            node->next = head ? (head->left ? head->left : head->right) : nullptr;
            
            connect(root->right);
            connect(root->left);
        }
        return root;
    }
};
```
- 对于任意一次递归，只考虑如何设置子节点的 next 属性,分为三种情况：
	- 没有子节点：直接返回
	- 有一个子节点：将这个子节点的 `next` 属性设置为同层的下一个节点，即为 `root.next` 的最左边的一个节点，如果 `root.next` 没有子节点，则考虑 `root.next.next`，依次类推
	- 有两个节点：左子节点指向右子节点，然后右子节点同第二种情况的做法
- 注意递归的顺序需要从右到左