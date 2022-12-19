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
        queue<Node*> qu;
        if(root==NULL)return root;
        qu.push(root);
        while(!qu.empty()){
            int size=qu.size();
            vector<Node*> ve;
            for(int i=0;i<size;i++){
                Node* temp=qu.front();
                ve.push_back(temp);
                if(temp->left!=NULL)qu.push(temp->left);
                if(temp->right!=NULL)qu.push(temp->right);
                qu.pop(); 
            }
            for(int i=0;i<size-1;i++){
                ve[i]->next=ve[i+1];
            }
            ve[size-1]->next=NULL;
        }
        return root;

    }
};
```