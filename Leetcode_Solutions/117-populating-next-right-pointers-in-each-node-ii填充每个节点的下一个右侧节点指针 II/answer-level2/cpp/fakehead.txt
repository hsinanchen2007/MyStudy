### 解题思路
比较难想到，自己按代码花个图就明白，实现上还是比较简单

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
      if(!root) return root;

      Node* fakeHead = new Node();
      Node* pre = fakeHead;
      Node* cur = root;

      while(cur){
        if(cur->left){
          pre->next = cur->left;
          pre = pre->next;
        }
        if(cur->right){
          pre->next = cur->right;
          pre = pre->next;
        }
        cur = cur->next;
        if(cur == NULL){
          pre = fakeHead;
          cur = pre->next;
          pre->next = NULL;
        }
      }
      return root;
    }
};
```