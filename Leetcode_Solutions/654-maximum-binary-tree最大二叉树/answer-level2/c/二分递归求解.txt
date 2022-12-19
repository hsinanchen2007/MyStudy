### 解题思路
1. 使用二分递归来构造这棵树
2. 每次选取数组的最大值作为根结点，左子树和右子树再次递归， 返回根节点
3. 递归结束条件数据组为空，注意只有一个数据时依然不能结束。

### 结果
执行用时 :60 ms
内存消耗 :28.4 MB

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
struct TreeNode* createTree(int* nums, int begin, int end) {

    if(begin>end){
        return NULL;
    }
    int max = begin;
    for(int i=begin+1; i<=end; i++){
        if(nums[i] > nums[max]){
            max = i;
        }
    }
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[max];
    root->left = createTree(nums, begin, max-1);
    root->right = createTree(nums, max+1, end);
    return root;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){

    return createTree(nums, 0, numsSize-1);
};


```