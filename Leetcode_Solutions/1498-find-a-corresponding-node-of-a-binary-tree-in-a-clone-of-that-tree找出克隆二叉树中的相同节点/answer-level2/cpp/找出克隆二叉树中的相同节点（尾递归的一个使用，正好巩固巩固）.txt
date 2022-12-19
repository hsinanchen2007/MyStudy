### 解题思路
此处撰写解题思路

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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==NULL) return original;
        if(original==target) return cloned;  //注意：按照这种返回值肯定是尾递归。。所以我们要特殊处理左右递归保证在子树里找到一个不等于NULL的就返回
        TreeNode * p=getTargetCopy(original->left,cloned->left,target);
        if(p!=NULL) return p;    //注意：这个就不要放在右递归表达式的下面了，找到了就可以直接返回了。。不需要多余的递归了
        TreeNode * q=getTargetCopy(original->right,cloned->right,target);
        if(q!=NULL) return q;
        return NULL;
    }
};
```