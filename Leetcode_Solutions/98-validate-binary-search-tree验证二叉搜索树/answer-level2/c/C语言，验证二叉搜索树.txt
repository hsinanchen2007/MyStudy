思路：引入上下边界
1. 对于树的每个节点 val ，设其上下边界 low , high。(用 long 防止 INT_MAX 溢出 )
2. 判断根结点时，须满足 low < val < high ，否则返回 false
3. 判断左节点时，仅 上界 变化 ( 新上界为 high 与 val 较小值。又因 val 必小于 high，故新上界为 val )
4. 判断右节点时，仅 下界 变化 ( 同理，新下界为 val )
 
```
bool fun(struct TreeNode* root, long low, long high) {
    if (root == NULL) return true;
    long num = root->val;
    if (num <= low || num >= high) return false;
    return fun(root->left, low, num) && fun(root->right, num, high);
}
bool isValidBST(struct TreeNode* root){
    return fun(root, LONG_MIN, LONG_MAX);
}
```
