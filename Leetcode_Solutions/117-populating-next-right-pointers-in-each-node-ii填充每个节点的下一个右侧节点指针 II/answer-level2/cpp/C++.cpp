### 解题思路
没什么好说的，细心就好

![image.png](https://pic.leetcode-cn.com/03150f1ed9da1aca7af93393b1b8a5a90280e4fdcc5cb18ff54b957147b8187f-image.png)

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
        if(root == NULL) return NULL;
        auto cur = root;
        while(cur) {
            Node* prev = NULL;
            Node* next = NULL;
            while(cur) {
                if(cur->left) {
                    if(!next) next = cur->left;
                    if(prev) prev->next = cur->left;
                    prev = cur->left;
                }
                if(cur->right) {
                    if(!next) next = cur->right; 
                    if(prev) prev->next = cur->right;
                    prev = cur->right;
                }
                cur = cur ->next;
            }
            cur = next;
        }
        return root;
    }
};
```