### 解题思路
对于一个结点，他要更新的值是他的右子树加上该结点的值，并且还要加上他的父节点传来的值（他的父节点已经更新完后的值）。那么就可以递归来解决问题。对于每次递归，需要完成的就是更新该结点的值，并且更新sum的值，这个sum值是传给左子树用的。
![image.png](https://pic.leetcode-cn.com/ec8463e9a82e27e9a86c3a32252cecc05cf40648dbcc2334d99b1a7c498c87b4-image.png)

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
    void change(TreeNode* root,int& sum)
    {
        if(!root) return;
        if(root->right)
        change(root->right,sum);//首先递归右子树，更新右子树的结点值以及sum值。这个sum值是传给左子树用的。
        sum+=root->val;//对于本次递归要完成的有两点，1.更新该结点的值，2.更新sum的值
        root->val=sum;
        if(root->left)//传递给左节点，循环递归。
        change(root->left,sum);

    }
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return NULL;
        int sum=0;
        TreeNode* p=root;
        change(root,sum);
        return p;
    }
};
```