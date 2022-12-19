### 解题思路

![Snipaste_2020-04-07_22-29-57.png](https://pic.leetcode-cn.com/eb980eec3ef74e637546fa7fc2eb602e098cf7623243b053ef9654d1c8fc4c2f-Snipaste_2020-04-07_22-29-57.png)

原题中，有这么一句话：**特别地，我们希望可以就地完成转换操作**。所以最好是能够不借助辅助容器来实现。

要实现起来也不复杂，我们需要实现一个$pair<Node*,Node*> recur(Node* root)$函数。这个函数将根节点为$root$的二叉树转换为一个**双向链表（不循环，即头节点的左指针不指向尾节点，尾节点的右指针也不指向头节点）**，并返回这个双向链表的头尾节点指针。

$recur$函数分三步实现：

1. 左子树调用$recur$，然后使左双向链表的尾节点和$root$节点拼接。

1. 右子树调用$recur$，然后使右双向链表的头节点和$root$节点拼接。

1. 返回左双向链表的头节点和右双向链表的尾节点。

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
        if(root==NULL)
            return NULL;
        pair<Node*,Node*> tmp=recur(root);
        tmp.first->left=tmp.second;
        tmp.second->right=tmp.first;
        Node *head=tmp.first;
        return head;
    }

    pair<Node*,Node*> recur(Node* root){
        pair<Node*,Node*> l={NULL,NULL},r={NULL,NULL},ans;
        if(root->left!=NULL){
            l=recur(root->left);
            l.second->right=root;
            root->left=l.second;
        }   
        if(root->right!=NULL){
            r=recur(root->right);
            r.first->left=root;
            root->right=r.first;
        }
        ans.first=l.first!=NULL?l.first:root;
        ans.second=r.second!=NULL?r.second:root;
        return ans;
    }
};
```