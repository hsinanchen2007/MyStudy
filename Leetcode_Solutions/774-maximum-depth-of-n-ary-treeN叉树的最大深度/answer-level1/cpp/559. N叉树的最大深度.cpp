
BFS，同时存储深度和当前节点，类似于[429. N叉树的层序遍历](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal)。


```c++ []
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;
        queue<Pair> que;
        que.push(Pair(1,root));
        int max_depth;
        while(que.size()){
            auto p = que.front();
            que.pop();
            max_depth = p.first;
            for(auto it : p.second->children){
                que.push(Pair(p.first+1, it));
            }
        }
        return max_depth;
    }
private:
    using Pair = pair<int, Node*>;
};
```