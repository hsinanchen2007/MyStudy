![批注 2020-03-13 132956.png](https://pic.leetcode-cn.com/5f7c4acb67ab322b582fa2509d4d18f32826bfe707ba6630171d34fcc9b4d7e6-%E6%89%B9%E6%B3%A8%202020-03-13%20132956.png)

```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int cnt=1,k=1;
    while(k<=numsSize)
    {
        cnt*=k;
        k++;
    }
    int ** res=(int **)malloc(sizeof(int *)*cnt);
    (*returnSize)=0;
    //(*returnColumnSizes)=(int *)malloc(sizeof(int)*cnt);
    f(nums,numsSize,0,res,returnSize,returnColumnSizes);
    return res;
}
void f(int* nums, int numsSize, int depth, int **res, int* returnSize, int** returnColumnSizes)
{
    if(depth==numsSize)
    {
        res[*returnSize]=(int *)malloc(sizeof(int)*numsSize);
        (*returnColumnSizes)[*returnSize]=numsSize;
        for(int i=0;i<numsSize;i++)
        {
            res[*returnSize][i]=nums[i];
        }
        (*returnSize)++;
        return;
    }
    for(int i=depth;i<numsSize;i++)
    {
        if(same(nums,depth,i))continue;
        swap(nums,depth,i);
        f(nums,numsSize,depth+1,res,returnSize,returnColumnSizes);
        swap(nums,depth,i);
    }
}
int same(int *nums, int from, int to)
{
    for(int i=from;i<to;i++)
    {
        if(nums[i]==nums[to])return 1;
    }
    return 0;
}
void swap(int *nums, int x,int y)
{
    int temp=nums[x];
    nums[x]=nums[y];
    nums[y]=temp;
}
```
