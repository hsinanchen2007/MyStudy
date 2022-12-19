![批注 2020-03-22 223449.png](https://pic.leetcode-cn.com/e7671e022d62d3671a59c8fa8bf578fd5452e89465693e701c613b09a2408eba-%E6%89%B9%E6%B3%A8%202020-03-22%20223449.png)

递归
思路很清晰，直接上代码


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
        vector<int> vec;
        solve(root,vec);
        return vec;
    }
    void solve(Node *root,vector<int> &vec)
    {
        if(!root)
            return;
        vec.push_back(root->val);
        for(const auto & elem:root->children)
            solve(elem,vec);
    }
};
```