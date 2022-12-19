执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户

内存消耗 :13.3 MB, 在所有 C++ 提交中击败了74.43%的用户

### 分析

一道二叉树深度遍历的题目，因为要求计算所有左叶子的和，在遍历二叉树时，需要加上一个标志位，用以表明当前是否为左侧子树。剩下的写法直接按照标准的深度遍历来写就好。

具体思路为：
1. 首先判断当前节点是否为空，若为空则直接返回0。
2. 若不为空则判断左右孩子是否均为空（即是否为叶子），若是叶子节点，则根据标志位flag的情况返回零或者节点值。
3. 若不为叶子节点，则对左右子树进行当前遍历算法，将二者的结果累加后返回。此处需要注意，左子树与右子树标志位不同。

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
int helper(TreeNode* root, bool flag){
    if(root == NULL)
        return 0;
    if(root -> left == NULL && root -> right == NULL && flag)
        return root -> val;
    return helper(root->left, true) + helper(root->right, false);
}
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
};
```