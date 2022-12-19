## 思路
如果A 和 B 当前节点值相等，则判断 B 节点的子树是否是 A 节点子树的子结构（**注意：** 此时B的子树中的空节点为A的子结构）
否则，递归判断 B 是否是 A 的左右节点的子结构

### 代码

```cpp
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;
        bool res = false;
        if (A->val == B->val) {
            res = helper(A, B);
        } else {
            res = isSubStructure(A->left, B) || isSubStructure(A->right, B);
        }
        return res;
    }

    bool helper(TreeNode *A, TreeNode *B) {
        if (!B) return true; //B为空为A的子结构，直接返回true
        if (!A || A->val != B->val) return false; //B不为空A为空 或 两者值buxiangde
        return helper(A->left, B->left) && helper(A->right, B->right);
    }
};
```