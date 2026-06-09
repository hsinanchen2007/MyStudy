### 解题思路


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
        if(root == NULL)
            return root;
        Node* dummy = new Node(0, NULL, NULL, NULL);
        Node* tail = dummy;
        Node* cur = root;
        while(cur)
        {
            if(cur->left)
            {
                tail->next = cur->left;
                tail = tail->next;
            }
            if(cur->right)
            {
                tail->next = cur->right;
                tail = tail->next;
            }
            cur = cur->next;
        }
        connect(dummy->next);
        return root;
    }
};
```