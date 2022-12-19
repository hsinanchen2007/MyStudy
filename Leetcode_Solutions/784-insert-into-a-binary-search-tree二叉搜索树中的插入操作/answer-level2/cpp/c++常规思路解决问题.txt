### 解题思路
![image.png](https://pic.leetcode-cn.com/bac81d036208e03b965457e36be9396fe0d1d3cc9f8373149a53447665317503-image.png)

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         TreeNode* p=root,*pre;
         while(root)
         {
             pre=root;
             if(root->val<val)
                root=root->right;
             else
                root=root->left;
         }
         if(pre->val<val) pre->right=new TreeNode(val);
         else pre->left=new TreeNode(val);
         return p;
    }
};
```