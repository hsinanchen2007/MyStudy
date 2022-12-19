### 解题思路
由二叉搜索树父节点左子树都小于父节点，右子树都大于父节点可知，找到大于p节点的最小节点等价于找到p节点右子树中的最左叶，或者p节点的祖宗节点中大于p的节点组中最小的那个（最靠近p节点，且p节点在其左子树中）。

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode * ret_ptr=nullptr;
        // right child
        TreeNode * p_child=p->right;
        if (p_child!=nullptr){
            while(p_child->left!=nullptr){
                p_child=p_child->left;
            }
        }
        // find last big father(bigger than p)
        TreeNode * p_father=root;
        TreeNode * big_father = nullptr;
        if (p_father!=nullptr){
            while(p_father!=p){
                if (p_father->val<p->val){
                    p_father = p_father->right;
                }else{
                    big_father = p_father;
                    p_father = p_father->left;
                }  
            }
        }

        if (p_child!=nullptr && big_father!=nullptr){
            ret_ptr = p_child->val<big_father->val?p_child:big_father;
        }
        if (p_child==nullptr){
            ret_ptr = big_father;
        }
        else{
            ret_ptr = p_child;
        }
        return ret_ptr;
    }
};
```