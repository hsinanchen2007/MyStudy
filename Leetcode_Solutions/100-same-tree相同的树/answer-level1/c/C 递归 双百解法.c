### 解题思路
将数分为不同的小子树，以此类推直到根结点返回
如果都为空树，返回true
其中一个不为空，则返回false
如果根结点相同，则分别判断左右子树的根结点是否相同
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :5.3 MB, 在所有 C 提交中击败了100.00%的用户
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
    if(p == NULL && q == NULL)
        return true;//都为空，相等。
    if(!p||!q)    //由于上面的判断不成立，则T1，T2至少有一个不为空
        return false;//一个空，一个不空，不相等
    if(p->val == q->val) //如果根节点相等
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);//判断左右子树是否都相等
    else 
        return false;
}
```