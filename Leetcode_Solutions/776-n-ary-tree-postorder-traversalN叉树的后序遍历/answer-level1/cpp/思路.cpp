### 解题思路
前序加翻转，注意和前序的进栈顺序

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
    vector<int> postorder(Node* root) {
      vector<int> res;
      if(!root) return res;

      stack<Node*> s;
      s.push(root);

      while(!s.empty()){
        Node* cur = s.top();
        s.pop();
        res.push_back(cur->val);

        for(auto node : cur->children){
          s.push(node);
        }
      }

      reverse(res.begin(), res.end());
      return res;    
    }
};
```