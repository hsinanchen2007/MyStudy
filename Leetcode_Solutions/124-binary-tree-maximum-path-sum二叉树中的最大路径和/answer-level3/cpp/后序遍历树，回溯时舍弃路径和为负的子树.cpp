### 解题思路
其实关键在于回溯时舍弃子树，并且要定义好cal()这个函数的意义：计算root为根节点向子结点延伸时连续的最大路径（要么接上左子树或右子树，要么不接）。即使root的子树中有更大的路径和也没关系，递归的时候用一个变量时时更新即可。
这道题其实就是就是带cost的无向无环图，也就是树的直径问题（只不过这里从根节点开始，并且只是二叉树，更简单了）。

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
    int max_d = -2e9; 
    int maxPathSum(TreeNode* root) {
        cal(root);
        return max_d;
    }
  //TC：O(n)
    int cal(TreeNode* root){
        if(root == NULL) return 0;
        int t = root->val;
        //postorder
        //<0的子树，还不如不要
        int leftsum = max(cal(root->left),0);
        int rightsum = max(cal(root->right),0);
        max_d = max(max_d,leftsum + rightsum + t);
        //没必要把0单独拿出来讨论，反正回溯的时候<0的左右子树是会舍弃的
        return max(leftsum,rightsum) + t;
    }
};
```