### 解题思路
此处撰写解题思路
![QQ图片20200315025030.png](https://pic.leetcode-cn.com/21062d30fdcf5c389811379a86e7e9e1d54badcb5776aec71756026b8e45ed1f-QQ%E5%9B%BE%E7%89%8720200315025030.png)

### 代码

```cpp
/**
 * Definition for a binary tree node.
![QQ图片20200315025030.png](https://pic.leetcode-cn.com/e5968931e8f4f271fb8add0174e3f3c78349512da4614f317da02142a8f5a97b-QQ%E5%9B%BE%E7%89%8720200315025030.png)
![QQ图片20200315025030.png](https://pic.leetcode-cn.com/459fba77af8bcafbd6fbef3c5310c7bfc7101f828dc350ec55f18ab2a51cd813-QQ%E5%9B%BE%E7%89%8720200315025030.png)
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool judge(TreeNode* A,TreeNode* B)
    {
        if((A==NULL&&B!=NULL)||(A!=NULL&&B==NULL))
            return false;
        if(A==NULL&&B==NULL)
            return true;
        if(A->val==B->val)
            return judge(A->left,B->right)&&judge(A->right,B->left);
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        TreeNode* A=root->left;
        TreeNode* B=root->right;
        return judge(A,B);
    }
};
```