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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //自己为自己的祖先
        if(root == NULL || root == p|| root == q)
        {
            return root;
        }
        TreeNode* leftCommonAnsceter  = lowestCommonAncestor(root->left,p,q);
        TreeNode* rigthCommonAnsceter = lowestCommonAncestor(root->right,p,q);

        //如果左边没有找到，那么右边公共祖先为最小祖先
        if(leftCommonAnsceter == NULL) {
            return rigthCommonAnsceter;
        }
        //如果右边没有找到，囊额左边公共祖先为最小祖先
        if(rigthCommonAnsceter == NULL){
            return leftCommonAnsceter;
        }
        //存在两个左右祖先，哪个上一个节点为最小祖先
        return root;
    }
};
```