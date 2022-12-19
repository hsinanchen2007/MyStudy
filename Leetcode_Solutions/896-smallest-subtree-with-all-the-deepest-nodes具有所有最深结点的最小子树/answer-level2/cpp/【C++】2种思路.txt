# 865. 具有所有最深结点的最小子树

## 题意

给定二叉树，求包含所有最深层叶子结点的最小子树（返回它们共同且最深的祖先结点）。

## 思路

这道题至少有以下两种解题思路。

### BFS + 反向查找

这是比较容易想到的方法：

1. 搜索（BFS/DFS）：定位到最深层叶子，同时建立结点到父结点的反向映射。时间为`O(N)`。
1. 找LCA：从最深层叶子开始沿着反向映射往上寻找LCA（直到集合收敛到同一个结点，该结点即答案）。平均时间为`O(logN)`。

```cpp
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // BFS，定位到最后一层
        // 同时记录结点的父结点
        unordered_map<TreeNode*, TreeNode*> getParent;
        vector<TreeNode*> currs = {root};
        while (true) {
            vector<TreeNode*> nexts;
            for (auto curr : currs) {
                if (curr->left) {
                    nexts.push_back(curr->left);
                    getParent.insert(make_pair(curr->left, curr));
                }
                if (curr->right) {
                    nexts.push_back(curr->right);
                    getParent.insert(make_pair(curr->right, curr));
                }
            }
            if (nexts.size() == 0) break;
            currs = nexts;
        }

        // 找LCA
        unordered_set<TreeNode*> children(currs.begin(), currs.end());
        while (children.size() > 1) {
            unordered_set<TreeNode*> parents;
            for (auto child : children) {
                parents.insert(getParent[child]);
            }
            children = parents;
        }
        return *children.begin();
    }
};
```

### DFS + 二分

目标结点因为到达最深层叶子结点的路径长度是相等的，所以一定是个平衡树，即它的左右子树高度相等。明确这一点之后，我们可以从根结点开始使用二分查找来定位到目标结点。对于一个结点，设左子树高度为`L`，右为`R`，那么：

- `L > R`：说明最深叶子在左子树，那么目标结点也在左子树
- `L < R`：同理说明目标结点在右子树
- `L == R`：第一个（也是最“浅”的）平衡子树，该结点就是答案，搜索终止

求出所有结点的深度需要`O(N)`，二分需要`O(logN)`，总的时间也是`O(N)`。

```cpp
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // 提前求所有结点的深度，用哈希表记录
        getDepth(root);
        // 二分查找目标结点
        return binarySearch(root);
    }

    TreeNode* binarySearch(TreeNode* node) {
        if (!node) return node;

        int leftDepth = node2Depth[node->left];
        int rightDepth = node2Depth[node->right];
        // 二分
        if (leftDepth == rightDepth) { // 左右子树等深 => 该结点就是答案
            return node;
        } else if (leftDepth > rightDepth) { // 左子树更深 => 答案在左子树
            return subtreeWithAllDeepest(node->left);
        } else { // 右子树更深 => 答案在右子树
            return subtreeWithAllDeepest(node->right);
        }
    }

    int getDepth(TreeNode* node) {
        if (!node) return 0;

        int dl = getDepth(node->left);
        int dr = getDepth(node->right);
        return node2Depth[node] = 1 + max(dl, dr);
    }

private:
    unordered_map<TreeNode*, int> node2Depth;
};
```