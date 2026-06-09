### 解题思路
定义一个全局变量res存储结果
递归结束条件
root==null，返回结果
当前节点的值在L和R之间时，就在res上加上节点的值
递归遍历左子树，右子树

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
    int res=0;
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root==NULL)  return res;
        if(root->val>=L && root->val<=R)    res+=root->val;
        
        rangeSumBST(root->left,L,R);
        rangeSumBST(root->right,L,R);
        
        return res;
    }
};
```