### 解题思路
1.因为节点值的不重复性，我们建一个1001长度的数组，来判断节点是否要删去（hash 除留余数法）
2.接着我们后序遍历即可，（函数的参数包括：当前节点、当前节点的父亲节点、方向[判断当前节点是左右节点]）

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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize){
    struct TreeNode **ans,*visual_head;
    int top=0,check[1001]={0};
    visual_head = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    visual_head->left = root;
    ans = (struct TreeNode**)malloc(sizeof(struct TreeNode)*1001);
    for (int i=0;i<to_deleteSize;i++)
        check[to_delete[i]] = 1;
    void DFS(struct TreeNode *rt,struct TreeNode *par,int flag){
        if (!rt)
            return;
        DFS(rt->left,rt,0);
        DFS(rt->right,rt,1);
        if (check[rt->val]){
            if (flag)
                par->right = NULL;
            else
                par->left = NULL;
            if (rt->left)
                ans[++top] = rt->left;
            if (rt->right)
                ans[++top] = rt->right;
            free(rt);
        }
    }
    DFS(root,visual_head,0);
    if (visual_head->left){
        ans[0] = root;
        *returnSize = top + 1;
        return ans;
    }
    *returnSize = top;
    return ans+1;
}
```