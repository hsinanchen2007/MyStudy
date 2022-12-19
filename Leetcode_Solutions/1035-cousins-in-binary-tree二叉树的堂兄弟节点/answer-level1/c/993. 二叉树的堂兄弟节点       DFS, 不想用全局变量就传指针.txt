### 解题思路
在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。

如果二叉树的两个节点深度相同，但父节点不同，则它们是一对堂兄弟节点。

我们给出了具有唯一值的二叉树的根节点 root，以及树中两个不同节点的值 x 和 y。

只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true。否则，返回 false。

 

示例 1：


输入：root = [1,2,3,4], x = 4, y = 3
输出：false



### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* depth(struct TreeNode* root, int z,  int cur_dep, int* z_dep){
    struct TreeNode * l = NULL, *r = NULL;

    cur_dep += 1;

    if(root->left){
        if (root->left->val == z){
            *z_dep = cur_dep;
            return root;
        }else{
            l = depth(root->left, z, cur_dep, z_dep);
        }
    }

    if(root->right){
        if (root->right->val == z){
            *z_dep = cur_dep;
            return root;
        }else{
            r = depth(root->right, z, cur_dep, z_dep);
        }
    }
    
    return l ? l : r;
}

bool isCousins(struct TreeNode* root, int x, int y){
    int x_depth = 1, y_depth = 1;
    struct TreeNode* parent_x = NULL, * parent_y = NULL;

    if(!root)
        return false;
    parent_x = depth(root, x, 1, &x_depth);
    parent_y = depth(root, y, 1, &y_depth);
    
    return  (x_depth == y_depth && parent_x != parent_y);
}
```