### 解题思路


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
        DFS(root, 1);
        return layer;
    }
    void DFS(Node* node, int n)
    {
        if(node->children.size() == 0)
        {
            layer = max(layer, n);
            return ;
        }
        for(int i = 0 ; i < node->children.size() ; ++i)
            DFS(node->children[i], n + 1);
    }
private:    
    int layer = 0;
};
```