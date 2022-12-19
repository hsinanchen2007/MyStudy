### 解题思路
平衡二叉树，属于有序树。用中序遍历(左中右))，可以得到一个递增的序列。按照题目的意思，我们其实需要的是一个倒序的序列。由此想到(右中左)的方式进行遍历，可以得到倒序。
然后用一个变量int val = 0累加每次历史遍历的值，然后赋值为当前，即可。

所以二叉树类的提醒，基本都是迭代的变种。只是要想到那个点

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
private:
    int val = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root){
            return NULL;
        }
        convertBST(root->right);
        val += root->val;
        root->val = val;
        convertBST(root->left);
        return root;
    }
};
```