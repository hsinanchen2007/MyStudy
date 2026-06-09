### 解题思路
![image.png](https://pic.leetcode-cn.com/1c4b2c4b87685fd2644c16754b387708b09594addd905fe3179696214294e71a-image.png)
这道简单题我开始想偏了方向，开始的思路是二叉树的中序遍历出来的序列是对称的即可，
后来用堆栈和队列以及二叉树的中序遍历求解，然后提交出错。之后仔细一想，才发现有些
不对称的二叉树的中序遍历序列也是对称的。所以之后换了一个思路。
**第100题让我们判断二叉树是否相同**
所以我从这里入手，既然要判断二叉树是否对称，只要二叉树的左子树和右子树对称即可。
但是，怎么判断二叉树的左子树和右子树对称呢？也就是在遍历的时候，遍历左子树的所访问的
节点和遍历右子树所访问的节点是一样的即可，于是便有了以下的代码：


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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return isMirror(root->left,root->right);
    }

    bool isMirror(TreeNode* p,TreeNode* q){
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        if(p->val==q->val && isMirror(p->left,q->right) && isMirror(p->right,q->left)){
            return true;
        }
        return false;
    }
};
```