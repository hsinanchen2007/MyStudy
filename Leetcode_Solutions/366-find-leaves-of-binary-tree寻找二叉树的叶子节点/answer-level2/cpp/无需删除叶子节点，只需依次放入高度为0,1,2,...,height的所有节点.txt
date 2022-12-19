我的Leetcode全部题解：[负雪明烛的博客](https://blog.csdn.net/fuxuemingzhu)，已更新800+道，欢迎大家关注。

我的做法比较新颖：计算每个节点的高度，依次放入高度为0,1,2,...,depth(root)的所有节点。

为什么？因为题目虽然让我们每次放入的都是叶子节点，而叶子节点的高度是0。当删除叶子节点时，会使剩余的每个节点的高度减一，此时`新的叶子节点`就是`如果不删除老叶子节点时高度为1`的节点……按照这个方法去做，就是依次放入高度为0,1,2,...,depth(root)的所有节点。

求树的高度用到了记忆化搜索，即代码中的node2depth，这是为了保存已经计算过高度的叶子节点，从而加速求树的高度的计算。

保存每个高度对应了哪些叶子节点的值，使用的是`倒排表`depth2node，其key是高度，value是该高度下对应的叶子节点的值。

DFS时遍历的方式选用的后序遍历，因为按照题目的要求，必须从左到右依次放入叶子节点，故遍历方式是`左孩子->右孩子->根节点`。

这个做法的好处是不用修改树的结构，比如做删除叶子节点的操作。

时间复杂度是O(N)，N为节点数。

C++代码如下：

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        int height = depth(root);
        for (int i = 0; i <= height; ++i) {
            res.push_back(depth2node[i]);
        }
        return res;
    }
    int depth(TreeNode* root) {
        if (!root) return -1;
        if (node2depth.count(root))
            return node2depth[root];
        int left = depth(root->left);
        int right = depth(root->right);
        int cur = max(left, right) + 1;
        depth2node[cur].push_back(root->val);
        node2depth[root] = cur;
        return cur;
    }
private:
    unordered_map<int, vector<int>> depth2node;
    unordered_map<TreeNode*, int> node2depth;
};
```