### 解题思路
此处撰写解题思路
求任意结点最大长度，要注意这个结点不一定是根节点。
一个结点的最大直径为左边的最大边数加上右边的最大边数
一个子树的最大边数即为其层数 + 1(子树与根节点之间的一条边)
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
    int length = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return length;
    }
    int depth(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        length = max(length,left + right);
        return max(left,right) + 1;
    }
};
```