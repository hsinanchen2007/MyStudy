### 解题思路
1. 根据二叉搜索树的特点，第一个值介于`[p->val, q->val]`之间的节点即为所求
2. 代码中第二个和第三个`if`都和`p->val`比较是完全ok的，因为假如当`p`无论是两者中较小值还是较大值，介于`[p->val, q->val]`的情况已经被第一个`if`match到了。因此假如是大于`p`的值，则是同时大于`p`和`q`的值的。小于同理

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((root -> val - p->val)*(root -> val - q ->val) <= 0 ){
            return root;
        }
        if(root -> val > p -> val){
            return lowestCommonAncestor(root -> left, p, q);
        }
        if(root -> val < p -> val){
            return lowestCommonAncestor(root -> right, p, q);
        }
        return NULL;
    }
};

```