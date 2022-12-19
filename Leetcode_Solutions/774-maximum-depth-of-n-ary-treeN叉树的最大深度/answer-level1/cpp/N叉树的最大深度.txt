# 迭代
广度优先搜索
程序如下：
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
        if(root == NULL){
            return 0;
        }
        queue<Node*> q;
        q.push(root);
        int res=0;
        while(!q.empty()){
            int n = q.size();
            res++;
            while(n--){
                vector<Node*> temp=(q.front())->children;
                q.pop();
                for(auto node : temp){
                    if(node){
                        q.push(node);
                    }
                }
            }
        }
        return res;
    }
};
```

时空代价高。

# 递归
还是递归好。
程序如下：
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
        int res = 0;
        if(root == NULL){
            return 0;
        }
        //找所有子树中最深的
        for(auto node : root->children){
            if(node){
                res = max(res,maxDepth(node));
            }
        }
        return res + 1;
    }
};
```