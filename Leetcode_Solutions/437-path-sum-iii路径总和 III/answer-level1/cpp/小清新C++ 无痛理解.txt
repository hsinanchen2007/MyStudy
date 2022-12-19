### 解题思路
递归方法，见注释

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
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        if(!root) return res;
        if(root->val == sum) res++;
        
        //和root节点无关的
        res += pathSum(root->left,sum);
        res += pathSum(root->right,sum);

        //和root有关的，这里不能直接调用pathSum,否则递归以后造成“断开的路径”
        res += pathSum_nroot(root->left,  sum - root->val);
        res += pathSum_nroot(root->right, sum - root->val);


        return res;
    }

    int pathSum_nroot(TreeNode* root, int sum) {   //这个函数只找包含root的路径
        if(!root) return 0;
        int res = 0;
        if(root->val == sum) res++;
        res += pathSum_nroot(root->left,sum - root->val); //自递归
        res += pathSum_nroot(root->right,sum - root->val);
        return res;
    }


};
```