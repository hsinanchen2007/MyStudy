### 解题思路
我这比较简洁点，虽然时间空间惨不忍睹哈哈，后续补迭代优化下:)

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
protected:
    vector<int> k;
public:
    vector<int> preorder(Node* root) {
        if(root==NULL)return k;
        k.push_back(root->val);
        for(auto i:root->children)
        if(i!=NULL)preorder(i);
        return k;               
    }
};
```