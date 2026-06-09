### 解题思路
此处撰写解题思路

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
        queue<Node*> q;
        Node* p = root;
        q.push(root);
        while(!q.empty())
        {
            int Size = q.size();
            for(int i = 0;i < Size;i++)
            {
                p = q.front();
                q.pop();
                if(i == Size - 1)
                {
                    p->next = NULL;
                }
                else
                {
                    p->next = q.front();
                }
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
        return root;
    }
};
```