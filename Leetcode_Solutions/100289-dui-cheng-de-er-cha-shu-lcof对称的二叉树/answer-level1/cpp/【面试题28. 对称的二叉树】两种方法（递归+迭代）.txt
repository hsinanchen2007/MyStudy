## 思路一：递归
利用镜像。

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }

    bool isMirror(TreeNode *root, TreeNode *copy) {
        if (!root && !copy) return true;
        if (!root || !copy) return false;
        if (root->val == copy->val) {
            return isMirror(root->left, copy->right) && isMirror(root->right, copy->left);
        }
        return false;
    }
};
```

## 思路二：迭代
将树的左右节点按相关顺序插入队列中，判断队列中每两个节点是否相等。

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> que;                
        que.push(root);
        que.push(root);
        while (!que.empty()) {
            TreeNode *node1 = que.front();
            que.pop();
            TreeNode *node2 = que.front();
            que.pop();
            if (!node1 && !node2) continue;
            if (!node1 || !node2 || node1->val != node2->val) return false;
            que.push(node1->left);
            que.push(node2->right);
            que.push(node1->right);
            que.push(node2->left);            
        }
        return true;
    }
};
```
