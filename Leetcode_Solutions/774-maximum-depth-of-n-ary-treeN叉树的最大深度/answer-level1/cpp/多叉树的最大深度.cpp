### 解题思路
此处撰写解题思路
要求的是多叉树的最大深度，一开始以为输入的是一个字符串数组，然后根据这个数组，实际上就是一个孩子表示法的一棵树。
递归边界可以是空结点或者叶子结点，这里前者我试了，但错了。不知道什么原因，有待改进。
另外，如果是叶子结点，从1开始计数，那么空节点要单独考虑。如果从0开始计数，那么边界为空节点为好，如果是叶子结点是边界，++res。
这里采用的是，res=0,叶子结点为边界，++res，空节点单独考虑的方式，至于用空节点做边界，如前所述
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
        int res=0;
        if(!root) return res;
        dfs(root,0,res);
        return ++res;
    }
    void dfs(Node* root,int level,int &res){
        
        if(root&&root->children.empty()){
            res = max(level,res);

            return;
        }
        for(int i=0;root&&i<root->children.size();i++){
            dfs(root->children[i],level+1,res);
        }
        return;
    }
};
```