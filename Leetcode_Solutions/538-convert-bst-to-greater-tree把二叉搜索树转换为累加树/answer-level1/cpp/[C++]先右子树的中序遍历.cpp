采用递归的方式，对原来的树进行“先右子树的中序遍历”，并使用一个成员变量cnt来记录“已访问过的节点 的val之和”即可。代码很简单，直接放代码。

```
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
    int cnt=0;  //用cnt来记录“已访问过的节点 的val之和”

    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL) return NULL;
        convertBST(root->right);
        cnt+=root->val;
        root->val=cnt;
        convertBST(root->left);
        return root;
    }
};
```