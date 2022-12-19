### 解题思路
这道题和钱一道题一样，可以用队列的方法来连接next。
唯一的不同就是在迭代时要判断是否有左右子树。

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
    // 执行用时 :24 ms, 在所有 C++ 提交中击败了41.60% 的用户
    // 内存消耗 :17.6 MB, 在所有 C++ 提交中击败了100.00%的用户
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 1;i<=n;++i){
                Node* temp = q.front();
                q.pop();
                if(i==n){
                    temp->next = NULL;
                } 
                else{
                    temp->next = q.front();
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return root;
    }


};
```