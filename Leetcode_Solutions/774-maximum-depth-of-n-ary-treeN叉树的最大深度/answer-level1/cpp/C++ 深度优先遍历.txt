### 解题思路
深度优先遍历

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
        if (root == NULL) {
            return 0;
        }
        int max_val = INT_MIN;
        height(root, 1, max_val);
        return max_val;
    }

    void height(Node* node, int level, int& max_val) {
        if (node->children.empty()) {
            max_val = std::max(max_val, level);
            return;
        }
        
        for (auto child : node->children) {
            std::cout << child->val << std::endl;
            height(child, level+1, max_val);
        }
    }
};
```
![码农黑板报.png](https://pic.leetcode-cn.com/23068fb54a9495c5c78ead6edb505ce602e7a2a4cac6230d3f2493a7c83849a2-%E7%A0%81%E5%86%9C%E9%BB%91%E6%9D%BF%E6%8A%A5.png)
