### 解题思路
想了整整一天，到第二天中午才调试出来
几个关键的地方
思考清楚问题的基本情况在于一个有三层的二叉树，这个时候我们要处理跨父节点的问题，所以我们肯定要用一个变量存储父节点;
每一次遍历我们都只考虑一层的内容，找到这一层的头结点，然后交替地去找两个相邻的节点，并把他们链接在一起;


寻找头部指针的思路:
```
// find c_head
while (NULL == c_head && NULL != parent) {
    if (NULL == parent->left && NULL == parent->right) {
        parent = parent->next;
        continue;
    }
    else if (NULL != parent->left) {
        c_head = parent->left;
    }
    else {
        c_head = parent->right;
    }
}
寻找下一个指针的思路
```
if (last_node == parent->right)
    parent = parent->next;
else if (last_node == parent->left) {
    if (NULL != parent->right)
        next_node = parent->right;
    else
        parent = parent->next;
}
else {
    if (NULL == parent->left && NULL == parent->right)
        parent = parent->next;
    else if (NULL != parent->left)
        next_node = parent->left;
    else
        next_node = parent->right;
}
```
### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node* parent = root;
        Node* p_head = root;

        while (NULL != p_head) {
            parent = p_head;
            Node* c_head = p_head->left;

            // find c_head
            while (NULL == c_head && NULL != parent) {
                if (NULL == parent->left && NULL == parent->right) {
                    parent = parent->next;
                    continue;
                }
                else if (NULL != parent->left) {
                    c_head = parent->left;
                }
                else {
                    c_head = parent->right;
                }
            }

            if (NULL == c_head)
                break;

            Node* last_node = c_head;
            Node* next_node = c_head->next;

            while (NULL != parent && NULL != last_node) {
                // find next_node not NULL
                while (NULL == next_node && NULL != parent) {
                    if (last_node == parent->right)
                        parent = parent->next;
                    else if (last_node == parent->left) {
                        if (NULL != parent->right)
                            next_node = parent->right;
                        else
                            parent = parent->next;
                    }
                    else {
                        if (NULL == parent->left && NULL == parent->right)
                            parent = parent->next;
                        else if (NULL != parent->left)
                            next_node = parent->left;
                        else
                            next_node = parent->right;
                    }
                }

                if (NULL == next_node) {
                    break;
                }

                last_node->next = next_node;
                last_node = next_node;
                next_node = NULL;
            }

            p_head = c_head;
        }

        return root;
    }
};
```