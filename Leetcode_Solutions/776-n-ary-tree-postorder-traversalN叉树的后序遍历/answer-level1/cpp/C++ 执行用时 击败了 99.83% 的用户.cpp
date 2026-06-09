### 解题思路
![1.png](https://pic.leetcode-cn.com/31ed066811203ccd379059b9e22b6c2e4bb9f2d64f9fc1100867dac958cd0530-1.png)

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
        vector<int>res;
        emplaceBack(root, res);
        return res;
    }

    void emplaceBack(Node* root, vector<int>& res) {
        if (!root)return;
        
        for (auto child : root->children)
            emplaceBack(child, res);
        res.emplace_back(root->val);
        return;
    }
};
```