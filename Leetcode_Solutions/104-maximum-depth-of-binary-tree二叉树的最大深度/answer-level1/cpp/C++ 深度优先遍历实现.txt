### 解题思路
二叉树的深度，首先想到的肯定要用到深度优先遍历。那么如何利用深度优先找到最深的层数呢？
- 我们定义一个Level用来记录每种可能的深度，max记录当前最大的深度。
- 递归的结束的条件是当前root为NULL
- 满足记录max的条件是root的左右孩子都是NULL,此时判断level是否大于max，大于就更新max的值。
- 若上述条件都不满足，则继续进行深度遍历，即调用自身函数进入更深的层次。
- 当遍历完root->right并且root->right==NUll函数返回后，需要将level--，然后回溯到上一层去判断另一分支的深度。
- 以此循环上述步骤，最终得到max为最大深度。
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
    void findmax(TreeNode *root,int &level,int &max){
        if(root==NULL){
            return;
        }
        level++;
        if(!root->left && !root->right){
            if(level > max){
                max = level;
            }
        }
        findmax(root->left,level,max);
        findmax(root->right,level,max);
        level--;
    }
    int maxDepth(TreeNode* root) {
        int level = 0;
        int max = 0;
        findmax(root,level,max);
        return max;
    }
};
```