    int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
        int MAX_LEN = 50000;
        *returnSize = 0;
        int** retArr = (int**)malloc(sizeof(int*) * MAX_LEN);
        if (root == NULL) {
            return retArr;
        }

        returnColumnSizes[0] = (int*)malloc(sizeof(int) * MAX_LEN);
        memset(returnColumnSizes[0], 0, MAX_LEN);
        struct TreeNode* Queue[MAX_LEN];
        int begin = 0, end = 0;
        int retPos = 0, ColumnSizes = 0;
        Queue[end++] = root;
        int flag = 0;
        retArr[*returnSize] = (int*)malloc(sizeof(int) * MAX_LEN);
        retArr[(*returnSize)++][returnColumnSizes[0][ColumnSizes++]++] = root->val;

        while (end > begin) {
        int i;
        int tmpEnd = end;
        retArr[*returnSize] = (int*)malloc(sizeof(int) * MAX_LEN);
        struct TreeNode* Stack[MAX_LEN];
        int top = -1;
        for (i = begin; i < tmpEnd; i++) {               
            if (Queue[i]->left != NULL) {
                if (flag == 0) {
                    Stack[++top] = Queue[i]->left;
                } else {
                    retArr[*returnSize][returnColumnSizes[0][ColumnSizes]] = Queue[i]->left->val;
                    returnColumnSizes[0][ColumnSizes]++;
                }
                Queue[end++] = Queue[i]->left;
            }
            if (Queue[i]->right != NULL) {
                if (flag == 0) {
                    Stack[++top] = Queue[i]->right;
                } else {
                    retArr[*returnSize][returnColumnSizes[0][ColumnSizes]] = Queue[i]->right->val;
                    returnColumnSizes[0][ColumnSizes]++;
                }
                Queue[end++] = Queue[i]->right;
            }                
        }
        if (flag == 0) {
            int k = 0;
            for (k = top; k >= 0; k--) {
                retArr[*returnSize][returnColumnSizes[0][ColumnSizes]] = Stack[k]->val;
                returnColumnSizes[0][ColumnSizes]++;
            }
        }
        flag = flag == 0 ? 1 : 0;
        begin = tmpEnd;
        ColumnSizes++;
        (*returnSize)++;
        }
        (*returnSize)--;
        return retArr;
    }