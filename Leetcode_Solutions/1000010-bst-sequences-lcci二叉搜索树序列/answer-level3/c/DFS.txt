![image.png](https://pic.leetcode-cn.com/531d3d5db51f4a5724877578becd0dd002787b787fc18b1c108db908978582cc-image.png)

### 解题思路

理解成数字排序，但排序要满足先有父节点、再有子节点的要求。
递归求解时，需要注意子节点一定要出现在对应父节点的后面。

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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int **outList = 0;
int outNum = 0;
int nodesNum = 0;


void GetAllSeq(struct TreeNode *node, struct TreeNode **list, int listNum, int *seq, int seqnum, int *flag)
{
    int i;
    if (seqnum >= nodesNum) {
        outNum++;
        outList = realloc(outList, sizeof(int *) * outNum);
        int *tmp = malloc(sizeof(int) * nodesNum);
        memcpy(tmp, seq, sizeof(int) * nodesNum);
        outList[outNum - 1] = tmp;
        return;
    }
    if (node->left != 0 && listNum < nodesNum) {
        list[listNum] = node->left;
        listNum++;
    }
    if (node->right != 0  && listNum < nodesNum) {
        list[listNum] = node->right;
        listNum++;
    }

    for (i = 0; i < nodesNum; i++) {
        if (flag[i] == 0 && list[i] != 0) {
            flag[i] = 1;
            seq[seqnum] = list[i]->val;
            GetAllSeq(list[i], list, listNum, seq, seqnum + 1, flag);
            flag[i] = 0;
        }
    }

    if (node->left != 0) {
        list[listNum - 1] = 0;
        listNum--;
    }
    if (node->right != 0) {
        list[listNum - 1] = 0;
        listNum--;
    }
}

void GetTreeNum(struct TreeNode* root, int *n)
{
    if (root != 0) {
        (*n)++;
    } else {
        return;
    }
    GetTreeNum(root->left, n);
    GetTreeNum(root->right, n);
}

int** BSTSequences(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    outList = 0;
    nodesNum = 0;
    outNum = 0;
    GetTreeNum(root, &nodesNum);

    if (root == 0) {
        *returnSize = 1;
        int *ret = malloc(sizeof(int));
        *ret = 0;
        *returnColumnSizes = ret;
        outList = malloc(sizeof(int *));
        return outList;
    }
    struct TreeNode **list = malloc(sizeof(struct TreeNode *) * nodesNum);
    memset(list, 0, sizeof(struct TreeNode *) * nodesNum);
    list[0] = root;
    int *seq = malloc(sizeof(int) * nodesNum);
    seq[0] = root->val;
    int *flag = malloc(sizeof(int) * nodesNum);
    memset(flag, 0, sizeof(int) * nodesNum);
    flag[0] = 1;
    GetAllSeq(root, list, 1, seq, 1, flag);
    free(list);
    free(flag);
    free(seq);
    *returnSize = outNum;
    int *ret = malloc(sizeof(int) * outNum);
    for (int i = 0; i < outNum; i++) {
        ret[i] = nodesNum;
    }
    *returnColumnSizes = ret;
    return outList;
}
```