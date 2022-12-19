### 解题思路
递归AC （关注微信公众号'码农黑板报'获取更多题解）
![image.png](https://pic.leetcode-cn.com/89d9e1aa00f2ad9b153ca962b239a3410e393b75aaaf74fc97bc3df0c9255b99-image.png)


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
        dfs(res, root);
        return res;
    }
    void dfs(vector<int>& res, Node* node) {
        if (node == NULL) {
            return;
        }
        for (auto child : node->children) {
            dfs(res, child);
        }
        res.push_back(node->val);
    }
};
```