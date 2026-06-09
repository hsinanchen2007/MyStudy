
# 递归方法
关于树的问题，尤其是跟左右相关的，递归其实是一种很常用的方法。
这一题的考虑是这样的，如果要求一棵树的左叶子之和，如果这棵树有左子树，有右子树，那么我分别对左右子树进行调用sumOfLeftLeaves函数，
然后求和不就可以得到最终的结果了吗？

于是就有了下面这行代码
```
return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
```

### 递归停止的条件1
然后我们需要另外考虑递归停止的条件。首先很简单的，root==NULL的话是return 0是很显然的。

### 递归停止条件2
但是这样还不够，我们还需要考虑返回值的情况。我们对左叶子进行考察，左叶子它的父亲会有哪些情况呢？ 它的父亲可能有右子树，也可能没有右子树。如果有右子树，那么我们需要把右子树里面的左叶子之和也进行求和，如果没有右子树，那么就直接得到左叶子的值，因此我们就有了下面这个条件：
```
if(isleaf(root->left)) return (root->left->val+sumOfLeftLeaves(root->right));
```
# 递归完整代码
```
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;
        if(isleaf(root->left)) return (root->left->val+sumOfLeftLeaves(root->right));
        else
        return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);

    }
    
    bool isleaf(TreeNode* root){
        if(root!=NULL&&root->left==NULL&&root->right==NULL)return true;
        else return false;
    }/*这个函数用来判断节点是否是叶子*/
};
```

