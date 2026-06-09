### 解题思路
1. 用一个变量`ans`存储最大深度
2. 当一个节点的孩子节点数组为空时，说明走到底了。将它所在的深度与当前的`ans`对比，前者较大则更新`ans`
3. 直到遍历所有的节点，返回`ans`

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
    int ans = 0;

    void dfs(Node* root, int depth){
        if((root->children).empty()){
            if(ans<depth) ans = depth;            
        }
        for(auto node: root->children){
            dfs(node, depth+1);
        }
    }

    int maxDepth(Node* root) {
        if(root == NULL) return ans;
        dfs(root, 1);
        return ans;
    }
};
```