**思路：**
参考题目中对平衡二叉树的定义：一个二叉树每个节点的左右两个子树的高度差的绝对值不超过1。
可以得到平衡二叉树的递归定义：当前结点的左右子树高度差绝对值不超过1，且当前结点的左右结点均是平衡二叉树。
**实现：**
先设一个`maxdeep`函数来求出当前结点的最大深度。之后转入正题，先求当前结点的左右深度，判断它们的绝对值差不超过1，再递归下去判断当前结点的左右子树是否是平衡二叉树。
**速度：**
执行用时 :8 ms, 在所有 C 提交中击败了95.36%的用户。内存消耗 :8.8 MB, 在所有 C 提交中击败了100.00%的用户。
```
int maxdeep(struct TreeNode* root){
    if(!root) return 0;
    int left = maxdeep(root->left);
    int right = maxdeep(root->right);
    return left > right ? left+1 : right+1;
}
bool isBalanced(struct TreeNode* root){
    if(!root) return true;
    int left = maxdeep(root->left);
    int right = maxdeep(root->right);
    return (left-right > -2 && left-right < 2
        && isBalanced(root->left) && isBalanced(root->right)); 
}
```
