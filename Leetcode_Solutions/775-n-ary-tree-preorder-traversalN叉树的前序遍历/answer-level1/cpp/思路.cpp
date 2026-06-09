### 解题思路
相对毕竟简单

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
      vector<int> res;
      if(!root) return res;

      stack<Node*> s;
      s.push(root);

      while(!s.empty()){
        Node* cur = s.top();
        s.pop();
        res.push_back(cur->val);

        for(int i = cur->children.size() - 1; i >= 0; i--){
          s.push(cur->children[i]);
        }
      }

      return res;      
    }
};
```