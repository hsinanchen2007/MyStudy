### 解题思路
递归法：每次找出左子树与右子树中深度最深的一个，将最深的那一颗树的深度加到当前节点，结束条件为子树节点为空；
迭代法：利用二叉树广度优先遍历的方法，依次遍历二叉树的每一层，每当访问到每层最后一个节点时，将深度加1。

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
//递归法
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        return (1 + max(maxDepth(root->left), maxDepth(root->right)));
    }
};
```

```cpp

//迭代法
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        queue<TreeNode*> q;
        TreeNode* temp, * lastNodeOfEachLayer;
        int height = 0;

        q.push(root);
        lastNodeOfEachLayer = root;

        while (!q.empty()) {
            temp = q.front();
            q.pop();

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }

            if (temp == lastNodeOfEachLayer) {
                height++;
                lastNodeOfEachLayer = q.back();
            }
        }

        return height;
    }
};
```