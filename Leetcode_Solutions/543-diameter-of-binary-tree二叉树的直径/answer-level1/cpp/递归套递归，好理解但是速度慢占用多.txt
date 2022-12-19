### 解题思路
此处撰写解题思路
一开始我以为只要算左右自树的深度相加就可以了，后来发现这题目竟然可以不经过根节点，只经过下面的子节点来达到最长的路径。
所以就写了一个递归套递归的方法，递归算出所有经过子节点的最长路径长度，并且和根节点的长度取最大值，但是这样速度并不快。
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
    int diameterOfBinaryTree(TreeNode* root) 
    {
        return depthforhead(root);
        
    }
    int depthforhead(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int c=depth(root->left)+depth(root->right);
        return max(c,max(depthforhead(root->left),depthforhead(root->right)));
    }
    int depth(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        return 1+max(depth(root->left),depth(root->right));   
    }
};
```