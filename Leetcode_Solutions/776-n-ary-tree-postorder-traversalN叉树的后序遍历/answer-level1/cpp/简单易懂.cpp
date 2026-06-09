### 解题思路
创建函数void f(Node* root,vector<int>& v)对n叉树进行后序遍历。

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
        
        for(int i=0;i<root->children.size();i++)
        {
            f(root->children[i],v);
        }
        
        v.push_back(root->val);
    }
};
```