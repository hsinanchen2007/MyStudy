 这个还是比较简单的东西，只要了解相同的树的定义即可，代码如下

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    
    if( p == NULL && q == NULL )
        return 1;
    // 如果 p,q 为空，则两树相等

    if( p == NULL || q == NULL)
        return 0;
    // 若 p,q 中只有一个为空，则两树必不相等 

    if( p->val != q->val)
        return 0;
    // 若两树结构相同但对应的值不同，则不相等

    return isSameTree(p->right,q->right) && isSameTree( p->left, q->left);
    // 递归的对 p,q 的左右子树调用函数并返回两函数的与值
}