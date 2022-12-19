### 解题思路
递归解法
注意返回值是全局变量
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
    vector<int> ans;
    vector<int> preorder(Node* root) {
        
        if(!root)return ans;

        ans.push_back(root->val);

        for(int i = 0;i < root->children.size();i++)
        {
            ans = preorder(root->children[i]);
        }
        return ans;
    }
};
```