### 解题思路

看到要让树非常的平衡，我就想到了用二分的方式，每次就把数组分成两个差不多大小的数组。这就用到了递归的思想。

思路基本上对了，但是代码一写一个错。经过反复的debug，我终于解决了我的bug，bug如下

- 用`malloc`分配内存后，要初始化左右两个child为NULL，虽然在我自己的编译器似乎能够保证默认情况就是NULL，但是在leetCode上必须要分配好。后续解题的时候我需要写一个函数专门用于创建，不然代码太冗余了
- `>>`的优先度低于 + -,因此需要把`(high-low)>>1`外套一个括号，否则，结果就不对劲了
- 要考虑数组为空的测试案例，可能是我做题少了，天天被这个坑。
- 一开始我就考虑终止条件为high-low==1的情况，还需要考虑high==low, 也就是最终只有2个和1个。

经测试

```c
    root->left = buildBST(nums, low, mid-1);
    root->right = buildBST(nums, mid+1, high);
```

和

```c
left = buildBST(nums, low, mid-1);
right = buildBST(nums, mid+1, high);
root->left = left;
root->right = right;
```

都是正确，毕竟都是最后的merge。

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


//因为是有序数组，因此可以用二分搜素的思想
//每次找中点，将数组一分为二， low-mid, mid-high
//

struct TreeNode * buildBST(int *nums, int low, int high)
{
    if (high == low){
        struct TreeNode *root;
        root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = nums[high];
        root->left = NULL;
        root->right = NULL;
        return root;    
    }
    if ( (high - low) == 1){
        struct TreeNode *root, *child;
        root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        child = (struct TreeNode *)malloc(sizeof(struct TreeNode));

        root->val = nums[high];
        child->val = nums[low];

        root->left = child;
        root->right = NULL;

        child->left = NULL;
        child->right = NULL;

        return root;
    }
    int mid = low + ( (high-low) >> 1) ;
    struct TreeNode *root, *left, *right;
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = buildBST(nums, low, mid-1);
    root->right = buildBST(nums, mid+1, high);
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    struct TreeNode *root;
    if (numsSize == 0){
        return NULL;
    }
    if (numsSize == 1){
        root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = nums[0];
        root->left = NULL;
        root->right = NULL;
        return root;
        }

    root = buildBST(nums, 0, numsSize - 1);
    return root;

}
```