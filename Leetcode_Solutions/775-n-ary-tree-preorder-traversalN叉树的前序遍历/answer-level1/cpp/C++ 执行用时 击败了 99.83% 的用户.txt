### 解题思路
![1.png](https://pic.leetcode-cn.com/020ec1b1e3e3a6ab09124ddb8cd96b3f8d49020bd98f4203a088cf9aa5cd915a-1.png)

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
        vector<int>res;
        emplaceBack(root, res);
        return res;
    }

    void emplaceBack(Node* root, vector<int>& res) {
        if (!root)return;
        
        res.emplace_back(root->val);
        for (auto child : root->children)
            emplaceBack(child, res);
        return;
    }
};
```