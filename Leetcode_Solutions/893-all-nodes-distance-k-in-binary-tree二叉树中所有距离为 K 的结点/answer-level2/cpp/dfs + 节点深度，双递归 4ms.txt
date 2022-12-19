### 解题思路
1. 首先使用dfs，求得从root ==> target的路径上经过的所有节点结合path
2. 从path中的每一个节点出发，寻找以该结点为根，向下搜索距离为深度为K的子节点
需要注意的是，必须避免重复搜索path中的节点

### 代码

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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        // 先深度优先，寻找到从root 到 target的节点路径
        vector<int> res;
        vector<TreeNode*> path;

        findTarget(root, target, path);
        int sz = path.size();
        // 寻找到path路径节点后，问题变为从path上的节点出发，到固定depth的问题
        for (int i = path.size() - 1; i >= 0 && K >= 0; --i) {
            if (K == 0) {
                res.push_back(path[i]->val);
                break;
            }
            if (i == sz - 1) {
                getNode(path[i], i, i + K, res);
            } else {
                // 广度优先，搜索非路径节点的其他子树
                TreeNode* p = (path[i]->left == path[i + 1]) ? path[i]->right : path[i]->left;
                getNode(p, i + 1, K + i, res);   // i + 1 + K - 1 ==> K + i
            }
            --K;
        }
        return res;
    }
    bool findTarget(TreeNode* root, TreeNode* target, vector<TreeNode*>& nodes) {
        if (root == nullptr) {
            return false;
        }
        nodes.push_back(root);
        if (root == target) {
            return true;
        }
        bool ret = findTarget(root->left, target, nodes);
        if (!ret && root->left) {
            nodes.pop_back();
        }
        if (!ret) {
            ret = findTarget(root->right, target, nodes);
            if (!ret && root->right) {
                nodes.pop_back();
            }
        }
        return ret;
    }
    void getNode(TreeNode* root, int depth, int k, vector<int>& res) {
        if (root == nullptr || depth > k) {
            return;
        }
        if (depth == k) {
            res.push_back(root->val);
            return;
        }
        ++depth;
        getNode(root->left, depth, k, res);
        getNode(root->right, depth, k, res);
    }
};
```