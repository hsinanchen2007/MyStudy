### 解题思路
定义一个作为结果的公共变量nums,每次递归时将该节点的直径和nums比较,大了就更新nums

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
    int nums;
public:   //和官方一样的思路，哈哈
    int diameterOfBinaryTree(TreeNode* root) { 
        if(root==NULL) return 0;
        nums=0;
        DFS(root);
        return nums;
    }
    int DFS(TreeNode *root){
        if(root==NULL) return 0;
        int left=DFS(root->left);
        int right=DFS(root->right);
        nums=max(left+right,nums);
        return max(left,right)+1;
    }
};
```