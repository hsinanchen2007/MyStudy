### 解题思路
本题想要求一个tree是否是对称的，起始可以通过镜像来判定。
如果一个tree是对称的需要满足以下条件：
1、当前结点的数值相等；
2、左节点包含的内容和右节点包含的内容相等。

那么和自身镜像对比的话，则为：
设定本身为tree，镜像为mirro_tree；
则满足以下几个条件：
1、tree->val = mirro_tree;
2、tree->left = mirro_tree->right；
3、tree->right = mirro_tree->left;
这样，递归下去，就可以判定一棵树是否是对称树了。

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
    bool is_mirro(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL) return 1;
        else if(root1 == NULL || root2 == NULL) return 0;
        else if(root1->val == root2->val){
            if(is_mirro(root1->left, root2->right) 
            && is_mirro(root1->right, root2->left)) return 1;
            else return 0; 
        }else return 0;
    }

    bool isSymmetric(TreeNode* root) {
        return  is_mirro(root, root);
    }
};
```