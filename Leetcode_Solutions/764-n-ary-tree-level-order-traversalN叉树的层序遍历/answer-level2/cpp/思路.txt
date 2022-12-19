### 解题思路
比较基础

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
    vector<vector<int>> levelOrder(Node* root) {
      vector<vector<int>> res;
      if(!root) return res;

      queue<Node*> s;
      s.push(root);

      while(!s.empty()){
        int size = s.size();
        vector<int> tmp;
        for(int i = 0; i < size; i++){
          Node* cur = s.front();
          s.pop();
          tmp.push_back(cur->val);

          for(auto node : cur->children){
            s.push(node);
          }
        }
        res.push_back(tmp);
      }

      return res;            
    }
};
```