### 解题思路
相对比较简单，熟悉层次遍历就好了

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
      if(root == NULL) return root;

      queue<Node*> q;
      q.push(root);
      Node* pre = NULL;

      while(!q.empty()){
        int tmp = q.size();
        for(int i = 0; i < tmp; i++){
          Node* node = q.front();
          q.pop();
          node->next = i == 0 ? NULL : pre;
          pre = node;
          if(node->right) q.push(node->right);
          if(node->left) q.push(node->left);
        }
      }

      return root;       
    }
};
```