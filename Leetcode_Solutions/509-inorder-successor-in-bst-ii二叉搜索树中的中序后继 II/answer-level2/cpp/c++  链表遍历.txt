### 解题思路
不要将这个当做树， 看做一条条链表就行了。
当node->right不为null时， 遍历以node->right为头结点，以left为next指针的链表，找最尾部的节点。
当node->right为null时，遍历以node->parent为头结点，已parent为next指针的链表，找第一个大于node->val的节点。
找到返回，都找不到则返回null。

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (!node) return node;
        if (!node->right) {
            Node* head  = node->parent;
            while (head) {
                if (head->val > node->val) break;
                head = head->parent;
            }
            return head;
        }
        Node* head = node->right;
        while (head->left) {
            head = head->left;
        }
        return head;
    }
};
```