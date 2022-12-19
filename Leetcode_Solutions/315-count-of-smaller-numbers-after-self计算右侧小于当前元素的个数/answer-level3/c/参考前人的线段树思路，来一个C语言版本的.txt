### 解题思路
此处撰写解题思路
参考前人的线段树思路，来一个C语言版本的，明天再做一个优化版本
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct tagSegTreeNode {
    int begin;
    int end;
    int count;
    struct tagSegTreeNode *left;
    struct tagSegTreeNode *right;
} SegTreeNode;

SegTreeNode * SegTreeBuild(int begin, int end)
{
    SegTreeNode *node = malloc(sizeof(SegTreeNode));
    int tmp = 0;
    node->begin = begin;
    node->end = end;
    node->count = 0;
    node->left = NULL;
    node->right = NULL;
    if (begin != end) {
        tmp = begin + (end - begin) / 2;
        node->left = SegTreeBuild(begin, tmp);
        node->right = SegTreeBuild(tmp + 1, end);
    }
    return node;    
}

void SegTreeInsert(SegTreeNode* root, int value, int step){

    if (root->begin == value && root->end == value) {
        root->count += step;
        return;
    }
    int tmp = root->begin + (root->end - root->begin) / 2;
    if (value >= root->begin && value <= tmp){
        SegTreeInsert(root->left, value, step);
    } else if (value > tmp && value <= root->end){
        SegTreeInsert(root->right, value, step);
    }

    root->count = root->left->count + root->right->count;
}


int SegTreeGetCount(SegTreeNode* root, int begin, int end){
    if (root == NULL || begin > end) {
        return 0;
    }
    if (begin == root->begin && end == root->end){
        return root->count;
    }
    int tmp = root->begin + (root->end - root->begin)/2;
    int left = 0;
    int right = 0;
    if (begin <= tmp) {
        left = SegTreeGetCount(root->left, begin, ((tmp < end) ? tmp : end));
    }
    if (tmp < end) {
        right = SegTreeGetCount(root->right, ((begin <= tmp) ? tmp + 1 : begin), end);
    }
    return (left + right);
}

int CmpHook(void *a, void *b) {
    return (*(int *)a - *(int *)b);
}
int* countSmaller(int* nums, int numsSize, int* returnSize){
    if ((numsSize == 0) || (nums == NULL)) {
        *returnSize = 0;
        return NULL;
    }
    int *sortNums = malloc(numsSize * sizeof(int));

    memcpy(sortNums, nums, numsSize * sizeof(int));    
 
    qsort(sortNums, numsSize, sizeof(int), CmpHook);
  
    int begin = sortNums[0];
    int end = sortNums[numsSize - 1];
    SegTreeNode *root = SegTreeBuild(begin, end);

    for (int i = numsSize - 1; i >= 0; i--){
        sortNums[i] = SegTreeGetCount(root, begin, nums[i] - 1);
        SegTreeInsert(root, nums[i], 1);
    }  
    *returnSize = numsSize;
    return sortNums;

}
```