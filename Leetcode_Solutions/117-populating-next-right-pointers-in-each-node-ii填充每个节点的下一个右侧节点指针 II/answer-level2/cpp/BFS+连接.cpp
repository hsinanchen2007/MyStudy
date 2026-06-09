![image.png](https://pic.leetcode-cn.com/d08b29dabc0e2a44aefcb7064053d6f62ffe400d27eb18669ea5de3da69004ec-image.png)


```
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
        queue<Node*> q;
        if(root)
            q.push(root);
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            connect_(temp);
            if(temp -> left)
                q.push(temp -> left);
            if(temp -> right)
                q.push(temp -> right);
        }
        return root;
    }
    void connect_(Node* root)
    {
        Node* next = nullptr;
        Node* temp_next = root -> next;
        while(temp_next && next == nullptr)
        {
            if(temp_next -> left)
                next = temp_next -> left;
            if(temp_next -> left == nullptr && temp_next -> right)
                next = temp_next -> right;
            if(temp_next -> left == nullptr && temp_next -> right == nullptr)
                temp_next = temp_next -> next;
        }
        if(root -> left && root -> right)
        {
            root -> left -> next = root -> right;
            root -> right -> next = next;
        }
        if(root -> left && root -> right == nullptr)
        {
            root -> left -> next = next;
        }
        if(root -> left == nullptr && root -> right)
        {
            root -> right -> next = next;
        }
    }
};
```
