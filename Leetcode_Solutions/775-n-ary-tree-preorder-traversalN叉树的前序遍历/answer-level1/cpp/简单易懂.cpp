### 解题思路
定义函数void f(Node* root,vector<int>& v)将n叉树所有节点值val前序遍历塞进容器v内。

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
        
        vector<int> v;
        
        f(root,v);
        
        return v;
        
    }
    
    void f(Node* root,vector<int>& v)
    {
        if(root==NULL)
        {
            return;
        }
        
        v.push_back(root->val);
        
        for(int i=0;i<root->children.size();i++)
        {
            f(root->children[i],v);
        }
    }
};
```