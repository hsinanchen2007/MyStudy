### 解题思路
1. 研究左子叶的特征结构，即访问root.left为叶子。也就是我们检查所有层，但只对左子树上的叶子确认累加。
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
    void traversingTree(TreeNode* root, int &sum){
        if (root == NULL) return ;
        if (root -> left && (root -> left -> left == NULL && root -> left -> right == NULL)) sum += root -> left -> val;
        traversingTree(root -> left , sum);
        traversingTree(root -> right, sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        traversingTree(root, sum);
        return sum;
    }
};
```