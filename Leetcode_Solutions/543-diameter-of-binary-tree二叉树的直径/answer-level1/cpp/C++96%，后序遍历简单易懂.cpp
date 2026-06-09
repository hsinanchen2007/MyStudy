### 解题思路
思路很简单，对于二叉树中每个节点，求该节点左右最长路径的和，最大的就是数的直径
运用后续遍历，先求左右子树的高度(既最长路径-1)，然后处理数据和暂存在maxl中的数进行比较，较大的暂存起来。
时间复杂度为O(n)。

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
    int maxl;
    int diameterOfBinaryTree(TreeNode* root) {
        maxl=0;
        deepOfTree(root);
        return maxl;
    }
    int deepOfTree(TreeNode* root){
        int left,right,deep;
        if(root==NULL){
            return -1;
        }
        left=deepOfTree(root->left);
        right=deepOfTree(root->right);
        deep=max(left,right)+1;
        maxl=max(maxl,(left+right+2));
        return deep;
    }
};
```