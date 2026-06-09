### 解题思路
bfs遍历树 + 统计每个节点深度，按深度从左到右输出，复杂度O(n).

### 代码

```c
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    //广度优先遍历 + 统计每个节点的深度
    int **res = (int **) malloc(sizeof(int *) * 1000);
    *returnColumnSizes = (int *) malloc(sizeof(int) * 1000);
    if (root == NULL) {
        *returnSize = 0;
        return res;
    }
    int hh = 0, tt = 0, idx = 0, row = 0, timestamp = 0;
    struct TreeNode* q[20000];
    int depth[20000], arr[20000];
    memset(depth, 0, sizeof depth);
    q[tt] = root;
    arr[idx++] = root->val;
    while (hh <= tt) {
        struct TreeNode* t = q[hh++];
        if (t->left != NULL) {
            arr[idx] = t->left->val;
            depth[idx++] = depth[timestamp] + 1;
            q[++tt] = t->left;
        }
        if (t->right != NULL) {
            arr[idx] = t->right->val;
            depth[idx++] = depth[timestamp] + 1;
            q[++tt] = t->right;
        }
        timestamp++;
    }

    //按高度拆分结果
    for (int i = 0, j = 0; i < idx; i++) {
        while (j < idx && depth[j] == depth[i]) j++;
        int col = 0;
        res[row] = (int *) malloc(sizeof(int) * (j - i));
        for (int k = i; k < j; k++) {
            res[row][col++] = arr[k];
        }
        (*returnColumnSizes)[row] = col;
        row++;
        i = j - 1;
    }
    *returnSize = row;
    return res;
}
```