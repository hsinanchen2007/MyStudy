### 解题思路
通过遍历寻找最大深度

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
    int maxDepth(Node* root) {
        if(!root)
            return 0;
        int depth = 0;
        for(Node* it : root->children)
            depth = max(maxDepth(it), depth);
        return ++depth;
    }
};
```