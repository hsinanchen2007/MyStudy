### 解题思路
前序遍历：
```
vector V;
void fun(tree){
    if(!tree) return V;
    V.push_back(tree->val);
    for(int i = 0;i<tree->children.size();i++){
        fun(tree->children[i]);
    }
    return V;
}
```
后序遍历
```
vector V;
void fun(tree){
    if(!tree) return V;
    
    for(int i = 0;i<tree->children.size();i++){
        fun(tree->children[i]);
    }
    V.push_back(tree->val);
    return V;
}
```




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
    vector<int> res;
    vector<int> preorder(Node* root) {
        if(!root) return res;
        res.push_back(root->val);
        for(int i = 0;i<root->children.size();i++){
            preorder(root->children[i]);
        }
        return res;
    }
};
```