# 1110. 删点成林

## 题意

给定二叉树`root`与待删除的结点值`toDeletes`，返回最终的森林（所有树组成的数组）。

## 思路

### 暴力

维护一个森林（队列）。遍历需要删除的值`val`：对当前队列中的每一个二叉树尝试删除`val`，若有一个二叉树成功找到并删除，将新树放入新队列。

时间：`O(N^2)`。代码：

```cpp
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& toDeletes) {
        currNodes.push(root);

        for (auto toDelete : toDeletes) {
            deleted = false;
            while (!currNodes.empty()) {
                TreeNode* curr = currNodes.front(); currNodes.pop();
                if (!deleted) {
                    TreeNode* next = delNode(curr, toDelete);
                    if (next) nextNodes.push(next);
                } else {
                    nextNodes.push(curr);
                }
            }
            nextNodes.swap(currNodes);
        }

        vector<TreeNode*> res;
        while (!currNodes.empty()) {
            res.push_back(currNodes.front());
            currNodes.pop();
        }
        return res;
    }

    TreeNode* delNode(TreeNode* node, int target) {
        if (!node) return node;

        if (node->val == target) {
            if (node->left) nextNodes.push(node->left);
            if (node->right) nextNodes.push(node->right);
            deleted = true;
            return NULL;
        }
        
        node->left = delNode(node->left, target);
        node->right = delNode(node->right, target);
        return node;
    }

private:
    queue<TreeNode*> currNodes, nextNodes;
    bool deleted;
};
```

### 哈希 + 后序遍历

对于二叉树来说，为了快速判断一个结点是否需要删除，可以提前将待删除的数组处理成集合，之后的操作就是在二叉树中删除某些结点。使用（带返回值的）后序遍历，即从最深层子结点开始删除，每删除一个子结点都要将断开的非空子树（最多2个）加入结果集。

这个方法比暴力法快的原因在于后序遍历：因为是从子结点开始删除，所以每当删除一个子结点，可以保证断开的子树中不会存在待删除的结点，所以一直只需要在主树的剩余部分遍历，不需要遍历多个二叉树。

时间：`O(N)`。代码：

```cpp
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& toDeletes) {
        currNodes.push(root);

        for (auto toDelete : toDeletes) {
            deleted = false;
            while (!currNodes.empty()) {
                TreeNode* curr = currNodes.front(); currNodes.pop();
                if (!deleted) {
                    TreeNode* next = delNode(curr, toDelete);
                    if (next) nextNodes.push(next);
                } else {
                    nextNodes.push(curr);
                }
            }
            nextNodes.swap(currNodes);
        }

        vector<TreeNode*> res;
        while (!currNodes.empty()) {
            res.push_back(currNodes.front());
            currNodes.pop();
        }
        return res;
    }

    TreeNode* delNode(TreeNode* node, int target) {
        if (!node) return node;

        if (node->val == target) {
            if (node->left) nextNodes.push(node->left);
            if (node->right) nextNodes.push(node->right);
            deleted = true;
            return NULL;
        }
        
        node->left = delNode(node->left, target);
        node->right = delNode(node->right, target);
        return node;
    }

private:
    queue<TreeNode*> currNodes, nextNodes;
    bool deleted;
};
```

## 反思

虽总结出两种思路，但感觉没有触及本质……待修改。