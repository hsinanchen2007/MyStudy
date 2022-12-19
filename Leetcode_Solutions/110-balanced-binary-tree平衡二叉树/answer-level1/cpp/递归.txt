### 解题思路
1.先定义一个公有变量flag，用来记录他是否为平衡二叉树。
2.怎么递归：树的根节点符合这个要求，意味着其他节点也要满足，所以采取递归。递归在任何一个结点我们得到它的左子树和右子树，按照判断左右子树相减的绝对值是否大于1， 将变化赋给flag，如果判断到一个节点的子树符合平衡二叉树，就返回他的最大高度（比较肯定是和每一个子树的最大高度比）。

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
    bool flag;
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        flag=true;
        DFS(root);
        return flag;
    }
    int DFS(TreeNode *root){
        if(root==NULL) return 0;
        int left=DFS(root->left);
        int right=DFS(root->right);
        if(fabs(left-right)>1) flag=false;
        return max(left,right)+1;
    }
};
```