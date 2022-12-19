### 方法：递归

首先分析路径的可能形态：
1. 倒V型路径，即从起点节点先向上一直到某个辈分最高的祖先节点k，然后从此祖先节点按照某条路径向下到某个子孙节点。
2. I型路径，即从某个子树的根节点一直向下，到某个子孙节点结束。

给定一棵以root为根的二叉树，

2. 1. 以root作为辈分最高的祖先节点，I型路径的最大值为disI=max(0, disI(root->left), disI(root->right))+root->val; (分别代表不选择左右子树，选择左子树、选择右子树延伸I型路径)
2. 以root为辈分最高的祖先节点，倒V型路径的最大值disV=max(0, disI(root->left)+disI(root->right))+root->val;

根据以上，递归计算根节点的disV，在递归过程中记录所有节点的disI、disV的最大值。

### C++代码

```c++
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
    int maxDis = INT_MIN;
    int maxPathSum(TreeNode* root) {
        disI(root);
        return maxDis;
    }
    int disI(TreeNode* root)
    {
        if(!root)
            return 0;
        int d1 = disI(root->left);
        int d2 = disI(root->right);
        int dis = max(0, max(d1, d2)) + root->val;
        maxDis = max(maxDis, dis);
        maxDis = max(maxDis, root->val + d1 + d2);
        
        return dis;
    }
};
```


### 时间复杂度：
O(N)