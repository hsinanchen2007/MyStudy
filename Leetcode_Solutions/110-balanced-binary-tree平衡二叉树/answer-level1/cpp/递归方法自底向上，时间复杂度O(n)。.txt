## 思路
&emsp;其实这道题很简单，我们想判断一棵树是否满足平衡二叉树，无非就是判断当前结点的两个孩子是否满足平衡，同时两个孩子的高度差是否超过1。
难点只是，我们要判断是否满足平衡树要通过高度，因此该过程需要求树的高度，这里我利用树的高度>=0，可以非负数充当满足，负数作为不满足来实现。
- 树的高度定义，叶子（空结点）结点高度为0
- 非叶结点高度定义>=1
- 不满足平衡树，高度<0

基于以上的定义。求解一个结点是否满足可以分为以下步骤,采用递归实现：
函数原型 `int CheckBalance(TreeNode* root);`
#### 递归边界,root为空
- `root` 为空，说明达到叶结点，返回高度0
#### root  非空时
-  `Lh = CheckBalance(root->left)`,检查左子树是否满足平衡，如果Lh小于0，根据定义，说明左子树不满足平衡，直接返回Lh即可
- `Rh = CheckBalance(root->right)`,检查右子树是否满足平衡，如果Rh小于0，根据定义，说明右子树不满足平衡，直接返回Rh即可。
- 左右子树均满足平衡后，判断`root`为根子树是否满足平衡二叉树，计算`abs(Lh-Rh)<2`，如果小于2，满足则返回`root`的高度，即`max(Lh,Rh)+1`,否则返回负数-1代表不满足。

## 代码
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
    bool isBalanced(TreeNode* root) {
        return CheckBalance(root)>=0;
    }
    int CheckBalance(TreeNode* root){
        if(!root)return 0; //空结点，说明到达底部，返回高度0
        int Lh=CheckBalance(root->left);//检查左子树高度
        if(Lh<0)//高度是否满足，负数相当于false，继续返回
            return Lh;
        int Rh=CheckBalance(root->right);//检查右子树高度
        if(Rh<0)//负数为false，直接返回
            return Rh;
        //左右子树都满足高度合法，检查当前根节点是否满足
        if(abs(Lh-Rh)<2)
            return max(Lh,Rh)+1;//满足，返回新的高度
        else
            return -1;//不满足，返回负数相当于false
    }
};
```
## 时间复杂度
每个结点仅访问一次，时间复杂度为$O(n)$。