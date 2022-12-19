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
//方法一：
class Solution {
public:
    Node* connect(Node* root) 
    {
        if(!root || !root -> left) return root;
        root -> left -> next = root -> right;
        if(root -> next)
            root -> right -> next = root -> next -> left;
        connect(root -> left);
        connect(root -> right);//另外写一个void函数也可！
        return root;
    }
};


//方法二：
//最开始的想法！层序遍历
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node *> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size; i++)
            {   
                Node* t1 = q.front();
                q.pop();
                if(i!=size-1){
                    Node* t2 = q.front();
                    t1->next=t2;
                }
                else{
                    t1->next=NULL;
                }
                
                if(t1->left)
                {
                    q.push(t1->left);
                }
                if(t1->right)
                {
                    q.push(t1->right);
                }
            }
        }
        return root;
    }
};

```