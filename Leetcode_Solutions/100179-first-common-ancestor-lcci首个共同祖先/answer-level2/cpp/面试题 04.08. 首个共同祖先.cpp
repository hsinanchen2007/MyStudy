### 回溯法

### 时间/空间复杂度
时间复杂度：O（nlogn）
空间复杂度：O（1）
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
        if(root==nullptr) return nullptr;                    //为空说明p或q都不属于当前子树，返回nullptr
        if(p==root||q==root) return root;                    //为p或则q说明其中至少有一个属于当前子树，返回root
        TreeNode* lft=lowestCommonAncestor(root->left,p,q);  
        TreeNode* rgt=lowestCommonAncestor(root->right,p,q);
        if(lft&&rgt) return root;                            //p，q既属于当前节点的左子树又属于右子树，说明是最进的公共祖先，返回
        return lft ? lft:rgt;                                //属于左子树，或者右子树，返回即可。
    }
};
```