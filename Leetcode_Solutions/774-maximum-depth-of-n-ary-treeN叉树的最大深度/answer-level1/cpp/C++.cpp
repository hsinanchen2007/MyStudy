### 解题思路
还有一个想法就是层次遍历来实现

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
        int maxDep = 0;
        for(int i = 0;i<root->children.size();i++)
            maxDep = max(maxDep,maxDepth(root->children[i]));
        return maxDep+1;
    }
};
```