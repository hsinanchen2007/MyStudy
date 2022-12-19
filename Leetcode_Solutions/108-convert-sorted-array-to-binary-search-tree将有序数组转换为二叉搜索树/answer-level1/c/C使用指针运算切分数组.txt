不需要额外编写一个用于递归的函数，因为C语言可以方便高效地“原地”切分数组，爷 I 了
```
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
  if (numsSize <= 0) return NULL;
  struct TreeNode* p = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
  p->val = nums[numsSize / 2];
  p->left = sortedArrayToBST(nums, numsSize / 2);
  p->right = sortedArrayToBST(nums + numsSize / 2 + 1, (numsSize - 1)/ 2);
  return p;
}
```
