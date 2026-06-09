### 解题思路
1. 如果初始的p和q如果全为空,则true;
2. 如果p和q有一个为空,另一个不为空,或者q指向的数据和q指向的数据值不同,那么不符合题意.
   前者不满足结构相同,后者不满足数值相同
3. 然后利用递归调用左子树和右子树,如果左右子树均返回1,则满足题意.
### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if(p == NULL && q == NULL) return true;
    else if(p == NULL && q != NULL || p != NULL && q == NULL ||(q->val != p->val))
    {
        return false;
    }
    else
    {
        return isSameTree(p->left, q->left) && isSameTree(p->right,q->right);
    }
}
```

### 总结
我第一遍做题最大的错误在于:忘记了先序遍历二叉树代码的模板是什么了!
对就是这么一个简单的递归模板,我居然忘记了.
你就说我多菜吧,勤能补拙,勤能补拙.