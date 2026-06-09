## 解题思路

* 对于每一个节点编号$id$来说（起始编号为1），其左孩子的编号为 $2*id$, 其右孩子的编号为$2*id+1$
* 所以，每一层的宽度为为当前层的 `最右边的节点编号 - 最左边的编号` ，维护一个全局最大，看哪一层宽度最大。


### BFS

本题最优解法为BFS层序搜索，原因是可以防止爆int。
最差情况下，每一层只有一个节点，然后全是右儿子。32层就直接爆int了，一共就32个节点就不能继续算下去了。
解决办法：假如当前层节点的个数为1，下一层重新开始计数，以当前层为节点1开始。不影响结果。但解决了id以2指数增长的形式。

```cpp
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;   // 节点，当前编号
        q.push({root, 1});
        int ret = 0;
        while (!q.empty()) {
            if (q.size() == 1) q.front().second = 1;  // 防止编号太大，重置编号不影响剩下树的宽度
            int left = q.front().second, right = left;
            int siz = q.size();
            while (siz--) {
                auto t = q.front().first;
                right = q.front().second; q.pop();
                if (t->left) q.push({t->left, 2 * right});
                if (t->right) q.push({t->right, 2 * right + 1});
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};
```

### DFS

利用先序遍历的特性：先序遍历每次都是先访问该层最左边的节点的，所以先把每层最左边的节点都存起来。
访问其他节点的时候就计算当前节点跟该层最开始节点的宽度，维护一个最大宽度即答案
DFS不能防止爆int，所以只能用`unsigned long long`表示id

```cpp
class Solution {
public:
    typedef unsigned long long ULL;
    
    int maxV_ = 0;       // maxV_ 是维护全局的最大宽度
    vector<ULL> start;   // 记录每一层开始的节点
    
    void dfs(TreeNode* root, ULL id, int depth) {
        if (!root) return;
        if (depth >= start.size()) start.push_back(id);
        maxV_ = max(maxV_, (int)(id - start[depth] + 1));
        dfs(root->left, id * 2, depth + 1);
        dfs(root->right, id * 2 + 1, depth + 1);
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 1, 0);
        return maxV_;
    }
};
```