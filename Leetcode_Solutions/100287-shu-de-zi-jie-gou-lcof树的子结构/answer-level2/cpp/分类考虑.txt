### 解题思路
首先我们考虑找到匹配的根结点，这个可以通过调用isSubStructure函数来实现，对于每一次寻找，我们都用深搜来判断这次是否可以找到答案。
在深搜中，我们只有碰到当前两个结点值相同时才深入，否则直接返回false，因为我们一路相等匹配下来，所以递归边界就是B为NULL的时候，这时就找到了匹配的一部分，只有当根结点相同并且左右子树也匹配时，我们才返回整个DFS的true。

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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == NULL)
            return false;
        if(A == NULL)
            return false;
        return DFS(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    bool DFS(TreeNode* A, TreeNode* B)
    {
        if(B == NULL)
            return true;
        if(A == NULL)
            return false;
        return A->val == B->val && DFS(A->left, B->left) && DFS(A->right, B->right);
    }
};
```