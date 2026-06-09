### 解题思路
递归大法解题重在思考每一步要考虑的操作
    要处理的操作
    要返回的值

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
    bool isBalanced(TreeNode* root) {
        return isBST(root)!=-1;
    }

    int isBST(TreeNode* pre){
        if(pre==NULL)
            return 0;
        
        int l=isBST(pre->left);
        int r=isBST(pre->right);
        if(l==-1||r==-1) return -1;

        return abs(l-r)>1?-1:1+max(l,r);
            
    }
};
```