### 解题思路
广度优先遍历，建立一个last指针指向每层最后一个节点，若是每层最后一个节点，则next指向空，否则指向下一个访问的结点

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
        if(!root) return nullptr;
        Node* p = root;
        Node* last = root;
        queue<Node*> que; que.push(root);
        while(!que.empty()){
            p = que.front(); que.pop();
            if(p->left) que.push(p->left);
            if(p->right) que.push(p->right);
            if(p == last){
                p->next = nullptr;
                last = que.back();
            }
            else
                p->next = que.front();
        }
        return root;
    }
};
```