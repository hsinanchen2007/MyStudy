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
void recur(struct TreeNode* root, int sum, int* path, int index, int** returnSize, int*** returnColumnSizes, int*** re){
    if(root == NULL)return;
    sum -= root->val;
    path[index++] = root->val;
    if(sum == 0 && root->left == NULL && root->right == NULL){
        **returnSize += 1;
       (**returnColumnSizes)[**returnSize - 1] = index;
       (*re)[**returnSize - 1] = (int*)malloc(index * sizeof(int));
       memcpy((*re)[**returnSize - 1], path, index * sizeof(int));
    }
    recur(root->left, sum, path, index, returnSize, returnColumnSizes, re);
    recur(root->right, sum, path, index, returnSize, returnColumnSizes, re);
    index--; // 不合适的时候，回退到上一个节点，path的状态（这一步很重要）
}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int initSize = 400; // 盲目地设置一个较大的路径数量，为returnColumnSizes和返回数组re开辟空间，程序最后会根据实际使用空间大小来进行缩小；当然也可以在程序的运行过程中为returnColumnSizes和re申请合适大小的内存空间，但是那样写太麻烦了，不如一刀切。
    *returnColumnSizes = (int*)malloc(initSize * sizeof(int));
    int** re = (int**)malloc(initSize * sizeof(int*));

    int path[10000]; // 暂存路径中的节点值
    int index = 0; // 给path当索引

    recur(root, sum, (int*)path, index, (int**)&returnSize, (int***)&returnColumnSizes, (int***)&re);

    if (*returnSize == 0){ // 一条都没有，那么就把之前申请的空间全部释放，返回NULL
        free(*returnColumnSizes);
        *returnColumnSizes = NULL;
        free(re);
        re = NULL;
        return NULL;
    }

    // 根据实际使用空间的大小，释放多余的空间
    *returnColumnSizes = (int*)realloc(*returnColumnSizes, (*returnSize) * sizeof(int));
    re = (int**)realloc(re, (*returnSize) * sizeof(int*));

    return re;
}
```
