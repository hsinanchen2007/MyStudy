### 解题思路
1. 函数dfsForRoot是在A中搜索B的根节点.
2. 一旦发现根节点则进入dfsForResult, 遍历两棵树是否相同, 注意出口的判断条件.
TIPS: 设置一个全局的状态earlyStop, 一旦发现结果就直接停止所有搜索, 同时该状态也是答案.

### 代码
![1.png](https://pic.leetcode-cn.com/356f01edc083a2c1c00f948d585063faf72e35e03eca0899cab57fe83310ea43-1.png)

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
    bool earlyStop = false;
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;
        dfsForRoot(A, B);
        return earlyStop;
    }

    void dfsForRoot(TreeNode* root, TreeNode* target) {
        if (!root || earlyStop) return;

        if (root->val == target->val) {
            earlyStop = dfsForResult(root, target);
            if (earlyStop) return;
        }

        dfsForRoot(root->left, target);
        dfsForRoot(root->right, target);
    }

    bool dfsForResult(TreeNode* A, TreeNode* B) {
        if (!A && !B) return true;
        else if (A && !B) return true;
        else if (!A && B) return false;

        if (A->val == B->val) {
            return dfsForResult(A->left, B->left) && dfsForResult(A->right, B->right);
        }
        return false;
    }
};
```