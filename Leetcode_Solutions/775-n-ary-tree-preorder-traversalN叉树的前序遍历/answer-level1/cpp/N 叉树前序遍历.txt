### 解题思路
此处撰写解题思路

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
    vector<int> re;
    vector<int> preorder(Node* root) {
        if (root==NULL) return re;
        PreOrder(root);
        return re;
    }
    void PreOrder(Node* root){
        if (root==NULL) return;
        re.push_back(root->val);
        for (int i=0; i<root->children.size(); i++){//遍历所有子节点
            PreOrder(root->children[i]);
        }
        return;

    }
};
```