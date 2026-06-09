### 解题思路

由于是二叉搜索树，所以这个题目尤其的简单；
+ 如果根节点比两个指定节点的值都大，说明该最近公共祖先在根节点的左子树
+ 如果根节点比两个指定节点的值都小，说明该最近公共祖先在根节点的右子树
+ 如果两个指定节点，一个比根节点大，一个比根节点小，说明根节点即为最近公共祖先

### 代码

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int num_p = p->val, num_q = q->val;
        if(root->val < min(num_p, num_q)){
            return lowestCommonAncestor(root->right, p, q);
        }else if(root->val > max(num_p, num_q)){
            return lowestCommonAncestor(root->left, p, q);
        }else{
            return root;
        }
    }
};
```