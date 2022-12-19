### 解题思路
使用BFS框架，执行用时击败63.73%。
思路：
1、一层一层入队，使用len记录每层的节点数；
2、取队首节点，将它出队，然后将它的next置为剩下的队首节点，每一层的最后一个节点的next为NULL。

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
        //BFS，一层一层连起来
        if (root==NULL || (root->left==NULL && root->right==NULL)) return root;
        queue<Node* > q;
        q.push(root);
        int len=0;
        while(!q.empty()){
            len=q.size();//记录每层节点数量
            while(len){
                Node* now=q.front();
                q.pop();
                if (now->left != NULL) q.push(now->left);
                if (now->right != NULL) q.push(now->right);
                if (len==1) now->next=NULL;//每一层最后一个节点
                else now->next=q.front();//置next为下一个节点
                len--;
            }
        }
        return root;
    }
    
};
```