递归思路
1.两个空指针绝对true。
2.如果p,q两个节点存在，并且相等，那么我们看他们的孩子节点是否也相等，只要返回是false那么这两个树绝对不相等
3.如果所有节点都没有不相等（全相等）返回true。

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (!p && !q)
        return true;
    if (p && q && p->val==q->val){
        if (isSameTree(p->left,q->left)==false)
            return false;
        if (isSameTree(p->right,q->right)==false)
            return false;
    }
    else
        return false;
    return true;
}