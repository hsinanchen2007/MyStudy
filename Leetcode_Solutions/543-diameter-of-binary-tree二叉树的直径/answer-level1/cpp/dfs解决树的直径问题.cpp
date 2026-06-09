本文是 https://leetcode-cn.com/problems/diameter-of-binary-tree/solution/c-di-gui-qiu-jie-by-frostime/
的详细解释，分享供大家阅读，希望对有疑惑的小伙伴有帮助！
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
class Solution
{
public:
    //这样的一个最长的直径肯定是以某个结点为根节点的子树的左右子树高度之和。只需要深搜遍历即可。
    int diameterOfBinaryTree(TreeNode* root){
        int distances = 0;
        dfs(root, distances);
        return distances;
    }
    //distances是以root为根节点的子树的最长路径，即root到其左子树的最深结点长度+root到其右子树的最深结点长度
    int dfs(TreeNode* root, int& distances) {
        if(!root) return 0;  // 根结点为空结点则最长路径肯定是0
        int leftHeight = dfs(root->left, distances);
        int rightHeight = dfs(root->right,distances);
        //当前以root为根结点（设此结点为A）的左右子树高度和是distances
        distances = max(leftHeight + rightHeight, distances);
        //这里的返回值会赋给A结点的父节点（设为B），而A是B的左结点。return的值应该是B的左子树，即A的最大直径+B结点本身，而            不能return A结点的distances+1
        return max(rightHeight, leftHeight)+1; 
    }
};
```