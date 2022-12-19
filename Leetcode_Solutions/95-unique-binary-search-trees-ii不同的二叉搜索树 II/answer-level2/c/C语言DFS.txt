贴个C语言的：

void AddNode(int val, struct TreeNode *left_res, struct TreeNode *right_res, struct TreeNode ***out, int *size)
{
    if (*out == NULL) {
        struct TreeNode **pout = (struct TreeNode **)malloc(sizeof(struct TreeNode*));
        pout[0] = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        pout[0]->val = val;
        pout[0]->left = left_res;
        pout[0]->right = right_res;
        *out = pout;        
    } else {
        struct TreeNode **temp = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * (*size + 1));
        struct TreeNode **pout = NULL;
        pout = *out;
        memcpy(temp, pout, sizeof(struct TreeNode *) * (*size));
        temp[*size] = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        temp[*size]->val = val;
        temp[*size]->left = left_res;
        temp[*size]->right = right_res;        
        *out = temp;
    }   
    (*size)++;
}

struct TreeNode** Dfs(int left, int right, int *size)
{
    struct TreeNode **out = NULL;
    if (left > right) {
        return NULL;
    }

    if (left == right) {
        AddNode(left, NULL, NULL, &out, size);
        return out;
    }
    
    for (int i = left; i <= right; i++) {
        int leftSize = 0;
        int rightSize = 0;
        struct TreeNode **left_res = Dfs(left, i - 1, &leftSize);
        struct TreeNode **right_res = Dfs(i + 1, right, &rightSize);
        
        if (left_res == NULL) {
            for (int j = 0; j < rightSize; j++) {
                AddNode(i, NULL, right_res[j], &out, size);
            }
        } else if (right_res == NULL) {
            for (int j = 0; j < leftSize; j++) {
                AddNode(i, left_res[j], NULL, &out, size);
            }
        } else {
            for (int j = 0; j < leftSize; j++) {
                for (int k = 0; k < rightSize; k++) {
                    AddNode(i, left_res[j], right_res[k], &out, size);
                }
            }
        }
    }
    return out;
}
struct TreeNode** generateTrees(int n, int* returnSize)
{   
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 0;
    return Dfs(1, n, returnSize);
}