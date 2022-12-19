## 思路一：递归
自底向上。

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```cpp
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return root;
        root->left = mirrorTree(root->left);
        root->right = mirrorTree(root->right);
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }
};
```

### 另一种写法
自顶向下。
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root) {
            TreeNode *tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            root->left = mirrorTree(root->left);
            root->right = mirrorTree(root->right);
        }        
        return root;
    }
};
```

### 化简
```c++
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root) {
            TreeNode *tmp = root->left;
            root->left = mirrorTree(root->right);
            root->right = mirrorTree(tmp);
        }        
        return root;
    }
};
```

## 思路二：迭代
层次遍历。
时间复杂度：O(n)
空间复杂度：O(n)
### 代码
```c++
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root) {
            queue<TreeNode*> que;
            que.push(root);
            while (!que.empty()) {
                TreeNode *node = que.front();
                que.pop();
                TreeNode *tmp = node->left;
                node->left = node->right;
                node->right = tmp;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }        
        return root;
    }
};
```


