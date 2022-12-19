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
        queue<Node*> cur;
        if(!root) return root;
        root->next = NULL;
        cur.push(root);
        while(!cur.empty()){
            int k=cur.size();
            for(int i=0;i<k-1;i++){
                Node* a=cur.front();
                cur.pop();
                a->next = cur.front();
                if(a->left) cur.push(a->left);
                if(a->right) cur.push(a->right);
            }
            cur.front()->next=NULL;
            if(cur.front()->left) cur.push(cur.front()->left);
            if(cur.front()->right) cur.push(cur.front()->right);
            cur.pop();                     
        }
        return root;        
    }
};
```