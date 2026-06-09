### 解题思路
利用一个start变量来记录voyage的遍历位置，如果root的值与voyage[start]的值不同，那么说明初始或者翻转后的树不符合规则，returnSize置1，ret[0]置-1并返回

当然首先需要判断root是否为空，或者voyage是否已经遍历完，这两种情况都是直接返回即可

如果上面的判断都通过了，就需要看是否需要翻转数组，如果root的左子树的值与voyage下一个位置的值不同，那么说明至少root的左右子树是要翻转的（至于翻转后是否满足规则，交给下次DFS的开头进行判断），翻转左右子树后再分别遍历左右子树，直到搜索成功或返回失败。

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
void DFS(struct TreeNode* root, int* voyage, int voyageSize, int *ret, int* returnSize, int *start)
{
    // 如果节点为空或voyage已经走完，直接返回
    if (root == NULL || *start == voyageSize) {
        return;
    }
    // 如果节点的值与当前待检查的值不同，则说明不存在相应路径，返回[-1]
    if (root->val != voyage[*start]) {
        ret[0] = -1;
        * returnSize = 1;
        return;
    }
    // 检查voyage下一个元素并判断是否需要翻转左右子树
    (*start)++;
    // 如果左子树不为空且值与voyage下一个元素不同说明至少是需要翻转的
    // 并不需要判断右子树的值或右子树是否存在
    if (root->left != NULL && root->left->val != voyage[*start]) {
        ret[(*returnSize)++] = root->val;
        struct TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    // 接下来分别遍历左右子树，直到走完路径或出现错误
    DFS(root->left, voyage, voyageSize, ret, returnSize, start);
    DFS(root->right, voyage, voyageSize, ret, returnSize, start);
    return;
}
int* flipMatchVoyage(struct TreeNode* root, int* voyage, int voyageSize, int* returnSize){
    // 待返回数组申请内存并初始化
    int *ret = (int *)malloc(sizeof(int) * 100);
    memset(ret, 0, sizeof(int) * 100);
    // start置为0，即从第一个元素开始检验是否符合规范
    int start = 0;
    // returnSize初始化为0
    * returnSize = 0;
    DFS(root, voyage, voyageSize, ret, returnSize, &start);
    return ret;
}
```