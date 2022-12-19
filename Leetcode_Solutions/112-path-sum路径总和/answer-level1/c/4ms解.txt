先判断头指针是否为空，不为空则进入递归函数：
1.递归停止条件：节点为空时，sum是否等于0；（每遍历一个节点sum就减去该节点的数值）
2.若左空右不空进右递归，若右空左不空进左递归；（保证能够到达叶子节点）
3.若都空或都不空就都进入递归，有true则true，全false则false。
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool haha(struct TreeNode* root, int sum){
    if(!root)
        if(sum==0)
            return true;
        else
            return false;
    if(root->left&&!root->right)
        return haha(root->left,sum-root->val);
    if(!root->left&&root->right)
        return haha(root->right,sum-root->val);
    return (haha(root->left,sum-root->val)||haha(root->right,sum-root->val));
}
bool hasPathSum(struct TreeNode* root, int sum){
    if(!root)
        return false;
    return haha(root,sum);
}
```
