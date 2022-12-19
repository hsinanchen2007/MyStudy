# 思路：
1）找区间的中间的数值
2）用递归分治， 每次中间值分别加入到树中，逐步返还

注意：其中对于中间数的index 不好找，因此（我觉得）用lo和hi来定位每次二分时的中点比较简单
# 代码：
```
struct TreeNode *creatnewnode(int num){
      struct TreeNode* temp = malloc(sizeof(struct TreeNode));
        temp->right = NULL;
        temp->left = NULL;
        temp->val = num;
        return temp;
}
struct TreeNode* recursionsortedarray(int* nums, int lo, int hi)
{
	if (lo >= hi) return NULL;

	int mid = (hi + lo) / 2;
    struct TreeNode* root =  creatnewnode(nums[mid]);
    root->left = recursionsortedarray(nums, lo, mid);
    root->right = recursionsortedarray(nums, mid + 1, hi);
	
    return root;

}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return recursionsortedarray(nums, 0, numsSize);
}

```

