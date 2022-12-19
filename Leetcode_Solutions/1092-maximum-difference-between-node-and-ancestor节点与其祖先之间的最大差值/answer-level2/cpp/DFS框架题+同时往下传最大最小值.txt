### 解题思路
代码执行用时击败5.23%，效率略低；
我的思路是DFS遍历每一个节点，再从每一个节点DFS开始找最大的差，算法复杂度O(n^2);
可以改进的思路，每次DFS时，同时把这条路径上的最大值和最小值往下传，到叶子节点时，就可以算出这条路径上的最大差了，再在所有的叶子节点的最大差中取最大值，算法复杂度O(n)

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
    int re=0;
    int maxAncestorDiff(TreeNode* root) {
        //DFS遍历每一个节点，再从每一个节点DFS开始找最小的数
        if (root==NULL) return 0;
        DFS(root);
        return re;
    }
    void DFS(TreeNode* root){
        if (root==NULL) return;
        re=max(re, DFS_Min(root, root->val));
        DFS(root->left);
        DFS(root->right);
        return;
    }
    int DFS_Min(TreeNode* root, int k){
        if (root==NULL) return 0;
        int left=DFS_Min(root->left, k);
        int right=DFS_Min(root->right, k);
        int ans=max(left, right);
        return (max(abs(root->val-k), ans));
    }
};
```