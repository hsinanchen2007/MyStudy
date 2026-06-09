方法一：利用搜索二叉树的特点

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
*二叉搜索树父结点与左右子结点值大小关系：left < parent < right
*整体思路：
*0.只要找到某个父结点，满足以上的大小关系即可，
*1.遍历二叉树，如果当前节点为NULL，直接返回NULL
*2.如果当前结点root小于右边q的值，且p的值大于root的值时，返回递归右子树的结果
*3.如果当前结点root大于右边q的值，且p的值小于root的值时，返回递归左子树的结果
*4.如果当前结点满足以上二叉搜索树的大小关系时，就直接返回当前结点
*/

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {

    if( root == NULL){

        return NULL;

    }

    if( q -> val > root -> val && p -> val > root -> val){

       return lowestCommonAncestor( root -> right , p , q );

    }else if( q -> val < root -> val && p -> val < root -> val ){

       return lowestCommonAncestor( root -> left , p , q );

    }

    return root;

}

```

方法二：一般情况的方法
    下面讨论的是如果二叉树不是搜素二叉树的情况时，如何处理。
    测试用例: 
    [8,4,2,9,12,13,1,3,5,11,7,10,21,15,16,31,17,22]
    4
    7
画出的二叉树图如下（便于读者验证）：
![)C`5TUVVN0)AL43S}3QAZTN.png](https://pic.leetcode-cn.com/0784d4280e83e782f267203e959d47ff5ea1f9943de344beb6e85cbfcb333ffe-\)C%605TUVVN0\)AL43S%7D3QAZTN.png)


```
/**
*
*以下代码针对一般情况下的二叉树，寻找两个结点最近的父结点，在本题中，同样可以通过。
*
*/

/**
*
*整体思路：
*1.判断当前结点是不是为NULL，如果是，直接返回NULL，
*2.判断当前结点是否为满足任意一个p,q，如果满足，则满足为最近的公共父结点
*3.遍历左子树，存储遍历结果l
*4.遍历右子树，存储遍历结果r
*5.判断是否满足t的左子树存在p->val右子树满足q->val的情况，如果是，直接返回t
*6.如果l不为NULL，直接返回l，
*7.返回r
*/

/**
*
*以下代码针对一般情况下的二叉树，寻找两个结点最近的父结点
*
*/

struct TreeNode * visitTree( struct TreeNode * t , int p , int q ){

    if( t == NULL ){

        return NULL;

    }

    if( t -> val == p || t -> val == q ){

        return t;

    }

    struct TreeNode * l = visitTree( t -> left , p , q );
    struct TreeNode * r = visitTree( t -> right , p , q );

    if( l != NULL && r != NULL ){

        return t;

    }

    if( l != NULL ){

        return l;

    }

    return r;

}

struct TreeNode * lowestCommonAncestor( struct TreeNode * root , struct TreeNode * p , 
                                                                    struct TreeNode * q) {
    
    return visitTree( root , p -> val , q -> val );

}
```

