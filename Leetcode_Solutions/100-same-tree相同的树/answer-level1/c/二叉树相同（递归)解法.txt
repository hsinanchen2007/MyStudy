### 解题思路
主要是分四种情况
1,p，q结点都为空，直接返回真
2,p结点为空，q不为空，直接返回假的
3，p结点为非空，q为空，直接返回假的

         **4.p结点非空，q结点非空**
若值相等继续递归遍历下一个节点，中途有不一样就返回假的，直到遍历所有的且都为真
若值不相等，不用递归遍历，直接返回假

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


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p==NULL && q==NULL )
    {
       return true;
    }
    else if(p==NULL&&q!=NULL)
        return false;
    else if(p!=NULL&&q==NULL)
        return false;
    else
    {
        if(p->val==q->val)
            return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        else
            return false;
    }
}


```