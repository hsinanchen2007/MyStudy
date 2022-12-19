### 解题思路
还没研究过二叉搜索树怎么原地转，这两天研究深度和广度优先，洗脑严重，就暴力做了：
1.深度优先遍历输入树，将节点值存在本地的数组中，同时记录节点个数
2.qsort本地数组，保证数组内的元素是递增的
3.根据本地数据直接构造一棵新的二叉搜索树

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
void DFS(struct TreeNode* root, int *numArr, int *cnt)
{
    if (root == NULL) {
        return;
    }
    numArr[(*cnt)++] = root->val;
    DFS(root->left, numArr, cnt);
    DFS(root->right, numArr, cnt);
    
    return;
}
int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
struct TreeNode *getBalance(int *numArr, int start, int end)
{
    int len = end - start;
    int mid = (end + start) / 2;
    if (len == 0) {
        return NULL;
    }
    struct TreeNode *ret = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    // 取中间的值作为根节点的值
    ret->val = numArr[mid];
    // 构造左子树
    ret->left = getBalance(numArr, start, mid);
    // 构造右子树
    ret->right = getBalance(numArr, mid + 1, end);

    return ret;
}
struct TreeNode* balanceBST(struct TreeNode* root){
    int numArr[10000] = { 0 };
    int cnt = 0;
    int i;
    // 深度优先遍历输入树，将节点值存在本地的数组中，同时记录节点个数
    DFS(root, numArr, &cnt);
    // qsort本地数组，保证数组内的元素是递增的
    qsort(numArr, cnt, sizeof(int), comp);
    // 根据本地数据直接构造一棵新的二叉搜索树
    struct TreeNode *ret = getBalance(numArr, 0, cnt);

    return ret;
}
```