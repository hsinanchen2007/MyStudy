### 解题思路


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
    int max_d = 0;
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) return 0;
        cal(root);
        //其实没必要从每个结点都开始
        //longestUnivaluePath(root->left);
        //longestUnivaluePath(root->right);
        return max_d;

    }
    //返回以root为根的最长路径
    //postorder
    int cal(TreeNode* root){
        if(root == NULL) return 0;
        int left = cal(root->left),right = cal(root->right);
        int samel = 0,samer = 0;
//如果val不一样的话，不用接上左右子树的相同最大路径
        if(root->left != NULL && root->left->val == root->val)
        {
           samel = left + 1;
        }
        if(root->right != NULL && root->right->val == root->val){
            samer = right + 1;
        }
        //如果和左右并不是相同的val，那就从0开始记起，反正max_d全局变量
        max_d = max(max_d,samel + samer);
        return max(samel,samer);
    }
};
```