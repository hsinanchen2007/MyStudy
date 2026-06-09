### 解题思路
判断二叉排序树。
一开始，一直想找到左树的最大值，右子树的最小值，然后判断当前结点值是否在两者之间。
采取后序遍历，这样左子树满足，右子树满足BST,否则就直接返回false。之后像上面说的再去判断当前结点值，是否在区间内。
然后为了去得到树的最大值，或者最小值，在这上面废了好久。都不可行。重新定义函数的话，耗费空间。得到左子树最大值也发生bug。
比如爷爷，双亲，右孩子，右孩子那棵树上返回最小值2，他有最大值6.  来到双亲结点那颗树时，要返回最大值。那么要么从双亲的根结点值，要么从右孩子的最大值，但是函数不一致。

接着想到，二叉排序树的性质。
若树是二叉排序树，那么中序遍历必是增序。逆否命题，如果不是增序，那么不是二叉排序树。
那么采用中序遍历，此时只需比较当前结点和前驱值即可！

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
    TreeNode* pre;  // 定义一个全局变量，记录当前结点前驱
    bool isValidBST(TreeNode* root) {
       if(!root) return true;
       if(!isValidBST(root->left)){
           return false;
       }
       if(pre&&pre->val>=root->val) return false;
       pre=root;
       if(!isValidBST(root->right)) return false;
       return true;
        
    }

};
```