### 解题思路
原理在[102题](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/ceng-ci-bian-li-bfs-by-user2511z/)二叉树的层次遍历中已经阐述, 本题属于同类型题。
下面给出深度优先搜索的实现

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
    vector<vector<int>> result;

    void dfs(Node* root, int dep){
        if(!root) return;
        if(dep == result.size()) result.emplace_back();
        result[dep].push_back(root->val);
        auto children = root->children;
        for(auto ele:children){
            dfs(ele, dep+1);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        dfs(root, 0);
        return result;
    }
};


```