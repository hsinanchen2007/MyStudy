### 解题思路
此处撰写解题思路
思路：将一个树想象为两个树得镜像问题即可，解法和上一题基本一致
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
 /*递归法*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }

    bool isMirror(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2)    return true;
        if(!root1 || !root2)    return false;
        if(root1->val != root2->val) return false;
        return (isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left));
    }
};
```

![image.png](https://pic.leetcode-cn.com/98809d47a8d33d8c0874a873887964f4242519a377f560e5eefba637100e2038-image.png)
