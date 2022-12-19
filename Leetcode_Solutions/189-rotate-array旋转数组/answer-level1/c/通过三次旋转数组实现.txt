### 解题思路

                                                1   2   3   4   5   6   7
第一次旋转0————numsSize-k-1                      4   3   2   1   5   6   7
第二次旋转numsSize-k————numsSize-1               4   3   2   1   7   6   5
第三次旋转0————numsSize-1                        5   6   7   1   2   3   4
### 代码

```c
void resverarr(int *nums, int left, int right);


void rotate(int* nums, int numsSize, int k){
    if(k%numsSize)
    {
        while(k>numsSize)
            k-=numsSize;

        resverarr(nums,0,numsSize-k-1);
        resverarr(nums,numsSize-k,numsSize-1);
        resverarr(nums,0,numsSize-1);
        
    }
}

void resverarr(int *nums, int left, int right)
{
    int mid=(left+right)/2;
    int temp;

    for(int i=0;i<=mid-left;i++)
    {
        temp=nums[left+i];
        nums[left+i]=nums[right-i];
        nums[right-i]=temp;
    }
}
```