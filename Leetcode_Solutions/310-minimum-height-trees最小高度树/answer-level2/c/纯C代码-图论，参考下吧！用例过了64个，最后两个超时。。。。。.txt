/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct tagTreeNode {
    int list[100];
    int cnt;
} TreeNode;

int getDeep(TreeNode *data, int pos, int fatherPos, int n) {
    int i;
    int max = 0;
    int deep;

    //边缘节点
    if (data[pos].cnt == 1 && data[pos].list[0] == fatherPos) {
        return 1;
    }

    for (i = 0; i < data[pos].cnt; i++) {
        if (data[pos].list[i] == fatherPos) {
            continue;
        }

        deep = 1 + getDeep(data, data[pos].list[i], pos, n); 
        if (max < deep) {
            max = deep;
        }
    }

    return max;
}

int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    TreeNode data[n];
    int *output = (int *)calloc(1, sizeof(int) * n);
    int i, j, dig1, dig2;
    int min = n;
    int deep = 0;

    memset(data, 0, sizeof(TreeNode) * n);
    *returnSize = 0;

    for (i = 0; i < edgesSize; i++) {
        dig1 = edges[i][0];
        dig2 = edges[i][1];
        data[dig1].list[data[dig1].cnt++] = dig2;
        data[dig2].list[data[dig2].cnt++] = dig1;
    }

    for (i = 0; i < n; i++) {
        if (data[i].cnt == 0) {
            deep = 1;
        } else {
            //用-1表示当前为根节点
            deep = getDeep(data, i, -1, n);
        }

        if (deep < min) {
            *returnSize = 0;
            output[(*returnSize)++] = i;
            min = deep;
        } else if (deep == min) {
            output[(*returnSize)++] = i;
        }
    }

    return output;
}