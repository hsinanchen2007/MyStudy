### 解题思路

定义一个全局变量，max

然后递归遍历左右子树，直到尽头。之后比较当前层数是不是比较大，如果是的话，更新max

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
    int max = 0;
    int maxDepth(TreeNode* root) {
        
        findMax(root,  0);
        return max;
    }
    void findMax(TreeNode* root, int n){
        if (root == nullptr) {
            if ( n > max ) max = n;
            return;
        }
        findMax(root->left, n+1);
        findMax(root->right, n+1);
        
        return;
    }
};
```