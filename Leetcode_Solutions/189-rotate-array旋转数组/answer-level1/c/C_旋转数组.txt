### 解题思路

### 代码

```c
//倒置数组Nums[LOW-HIGH]的数
void fanZhuan(int* Nums,int Low,int High)
{
    while(Low<High)
    {
        int temp=Nums[Low];
        Nums[Low]=Nums[High];
        Nums[High]=temp;
        ++Low;--High;
    }
}

void rotate(int* nums, int numsSize, int k){
    k=k%numsSize;
    fanZhuan(nums,0,numsSize-1);
    fanZhuan(nums,0,k-1);
    fanZhuan(nums,k,numsSize-1);
}
```