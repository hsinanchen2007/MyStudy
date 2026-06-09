### 解题思路
这道题想了好久。有两种方法。一是直接递归，二是用队列。

直接递归的方法是先把左右子树相连。再看该节点是否有next节点，有就把该节点的右节点和它next节点的左节点连接起来。相当于先搭桥。
if(root->next){//若它有next，就把它的右子节点和它的next的左子节点连接在一起。
            root->right->next = root->next->left;
        }


队列的方法就是把节点依次压入队列里，这里重要的是用一个for循环
int n = q.size();//记录每一层的节点个数。
for(int i = 1;i<=n;++i){}
来控制每一层的节点数。并连接。

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
    // 执行用时 :32 ms, 在所有 C++ 提交中击败了43.18% 的用户
    // 内存消耗 :16.9 MB, 在所有 C++ 提交中击败了100.00%的用户
    Node* connect(Node* root) {
        if(!root||!root->left) return root;
        root->left->next = root->right;//这里直接把左子节点和右子节点连接在一起。
        if(root->next){//若它有next，就把它的右子节点和它的next的左子节点连接在一起。
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }


    // 执行用时 :36 ms, 在所有 C++ 提交中击败了29.58% 的用户
    // 内存消耗 :17.3 MB, 在所有 C++ 提交中击败了100.00%的用户
    Node* connect(Node* root){
        if(!root||!root->left) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();//记录每一层的节点个数。
            for(int i = 1;i<=n;++i){
                Node* temp = q.front();//取出一个节点
                q.pop();
                if(i==n)//若这个节点是本层最后一个节点，那么他的next为nullptr
                    temp->next = nullptr;
                else{
                    temp->next = q.front();//否则他的next为下一个节点
                }
                if(temp->left){//若该节点有左子节点，就把它的左右子节点加到队列里去。
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
        }
        return root;
    }
};
```