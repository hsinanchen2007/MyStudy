C语言的解法太少了，而且不是很容易看懂，内存可能还能再优化下，欢迎指正

struct TreeNode** makeRoots(int start, int end, int* returnSize){
    if (start > end) {
        *returnSize = 1;
        struct TreeNode **leaf = malloc(sizeof(struct TreeNode*));
        //leaf[0] = malloc(sizeof(struct TreeNode));
        leaf[0] = NULL;
        return leaf;
    }
    if (start == end) {
        *returnSize = 1;
        struct TreeNode **leaf = malloc(sizeof(struct TreeNode*));
        leaf[0] = malloc(sizeof(struct TreeNode));
        leaf[0][0].val = start;
        leaf[0][0].left = NULL;
        leaf[0][0].right = NULL;
        return leaf;
    }
    int possible = 0;
    struct TreeNode** result = malloc(sizeof(struct TreeNode*));
    result[0] = malloc(sizeof(struct TreeNode));
    // 遍历所有可以作为root value的值
    for (int value = start; value <= end; value++) {
        int leftSize = 0;
        int rightSize = 0;
        struct TreeNode** resultLeft = makeRoots(start, value - 1, &leftSize);
        struct TreeNode** resultRight = makeRoots(value + 1, end, &rightSize);
        *returnSize = *returnSize + leftSize * rightSize;
        for (int i = 0; i < leftSize; i++) {
            for (int j = 0; j < rightSize; j++) {
                result = realloc(result, (possible + 1) * sizeof(struct TreeNode*));
                result[possible] = malloc(sizeof(struct TreeNode));
                result[possible][0].val = value;
                result[possible][0].left = resultLeft[i];
                result[possible][0].right = resultRight[j];
                possible++;  
            }
        }
    }
    return result;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** generateTrees(int n, int* returnSize){
    *returnSize = 0;
    if (n < 1) {
        return NULL; 
    }
    return makeRoots(1, n, returnSize);
}