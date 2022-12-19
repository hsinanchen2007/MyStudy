类似二分查找，数组中间的为root，root->left指向左半边数组中间那项，root->right指向右半边数组中间那项，递归。
```c
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if(numsSize==0) return 0;
    struct TreeNode* root=malloc(sizeof(struct TreeNode));
    if(numsSize<=2){
        root->left=0;
        root->right=0;
        root->val=nums[0];
        if(numsSize==2){
            struct TreeNode* higherRoot=malloc(sizeof(struct TreeNode));
            higherRoot->left=root;
            higherRoot->right=0;
            higherRoot->val=nums[1];
            return higherRoot;
        }
    }
    else{
        int i;
        int left[(numsSize-1)/2];
        int right[numsSize/2];
        for(i=0;i<(numsSize-1)/2;i++)
            left[i]=nums[i];
        for(i=(numsSize+1)/2;i<numsSize;i++)
            right[i-(numsSize+1)/2]=nums[i];
        root->val=nums[(numsSize-1)/2];
        root->left=sortedArrayToBST(left,(numsSize-1)/2);
        root->right=sortedArrayToBST(right,numsSize/2);
    }
    return root;
}
```