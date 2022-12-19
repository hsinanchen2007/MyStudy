### 解题思路
迭代，不用递归，一个while循环即可。

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
        int p_val=p->val;
        int q_val=q->val;
        TreeNode* node=root;
        while(node!=NULL){
            int parent_val=node->val;
            if(p_val<parent_val&&q_val<parent_val){
                node=node->left;
            }else if(p_val>parent_val&&q_val>parent_val){
                node=node->right;
            }else{
                return node;
            }
        }
        return node;
    }
};
```