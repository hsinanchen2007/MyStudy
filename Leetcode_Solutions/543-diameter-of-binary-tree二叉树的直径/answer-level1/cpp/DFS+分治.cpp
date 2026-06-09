### 解题思路
用DFS来遍历每一个节点计算其深度，分治来判断最长路径是否经过该节点。

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
    int maxpath = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        depth(root, 0);
        return maxpath -1 ;
    }
    int depth(TreeNode* root, int dep){
        int L = 0, R= 0;
        if(root->right != NULL) R = depth(root->right, dep+1);
        if(root->left != NULL) L = depth(root->left, dep+1);
        maxpath = max(maxpath, L + R + 1);
        return max(L, R)+ 1;
    }
};
```