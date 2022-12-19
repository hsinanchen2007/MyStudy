### 解题思路
利用栈存储节点，取出栈顶元素，将它的子节点逆序存入栈中。
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
        vector<int> ans;
        if(root == NULL)
        return ans;
        stack<Node*> nodes;
        nodes.push(root);
        while(!nodes.empty())
        {
            Node* nownode = nodes.top();
            nodes.pop();
            ans.push_back(nownode -> val);
            for(int i = nownode -> children.size() - 1; i >= 0; i --)
            nodes.push(nownode -> children[i]);
        }
        return ans;
    }
};
```