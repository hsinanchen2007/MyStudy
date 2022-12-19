### 解题思路
- 先用递归解决，递归可以辅助迭代法的思考
- 二叉树是否对称，等价于根节点的两个子树是否对称
- 两个树是否对称：
  停止: 根节点都为空，或者其中一个根节点为空，或者两个根节点都不为空且值不同
  递归: 每棵树的左子树都与另一个树的右子树对称

### 递归
```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return true;
        if (t1 == nullptr || t2 == nullptr) return false;
        if (t1->val != t2->val) return false;
        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};
```

### 迭代
```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode *> quk;    // 这里用 queue 或者 stack 都可以，只要调整好结点的插入顺序就行
        quk.push(root->left);
        quk.push(root->right);
        while (!quk.empty()) {
            TreeNode *t1 = quk.front();
            quk.pop();
            TreeNode *t2 = quk.front();
            quk.pop();
            if (t1 == nullptr && t2 == nullptr) continue;
            if (t1 == nullptr || t2 == nullptr) return false;
            if (t1->val != t2->val) return false;
            quk.push(t1->left);
            quk.push(t2->right);
            quk.push(t1->right);
            quk.push(t2->left);
        }
        return true;
    }
};
```