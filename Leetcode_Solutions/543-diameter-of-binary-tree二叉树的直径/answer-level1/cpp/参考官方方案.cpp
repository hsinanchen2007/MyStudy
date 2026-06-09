### 解题思路
递归

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
    int val;       
    int fanhui(TreeNode * treeNode)
    {
        if(NULL==treeNode) return 0;
        int L=fanhui(treeNode->left);
        int R=fanhui(treeNode->right);
        val=max(L+R,val);       //纪录最大的  左右子树深度之和
        return max(L,R)+1;      //返回子树左右子树较大者  并加上当前的节点
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        val=0;
        fanhui(root);
        return val;
    }
};
```