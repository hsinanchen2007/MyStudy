### 解题思路
最多边的路径其实也就是最多结点数的路径。

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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 0;
        
        int maxv = 0; //这个是路径的结点数，所以返回前要减去1.
        depth(root,maxv); 
        return maxv-1;
    }

    //这个函数返回高度，但在计算过程顺便把最长的路径长度存在maxv中。
    int depth(TreeNode* root,int& maxv){
        if(!root) return 0;
        int left = depth(root->left,maxv);
        int right = depth(root->right,maxv);
        
        int path_nodes = left + right + 1;
        maxv = max(maxv,path_nodes); //更新为最多结点的路径的结点数

        return max(left,right) + 1;
    }
};
```