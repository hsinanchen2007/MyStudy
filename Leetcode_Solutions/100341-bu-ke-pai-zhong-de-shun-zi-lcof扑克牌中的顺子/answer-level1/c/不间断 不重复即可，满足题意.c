### 解题思路
//不间断 不重复即可
//1.最大值减去最小值 >4 永远也不能补上 就算是剩下的全为0也补不上
//2.判断是否重复  除开0的数是否重复

### 代码

```c

int compare(void *n1,void*n2)
{
    return *(int*)n1-*(int*)n2;
}
bool isStraight(int* nums, int numsSize){
    int i=0;
    qsort(nums,numsSize,sizeof(int),compare);
    int max=nums[numsSize-1];
    int min =0;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]!=0)
        {
            min=nums[i];
            break;
        }  
    }
    for( i=1;i<numsSize;i++)
    {
        if(nums[i]==nums[i-1]&& nums[i]!=0)
            return false;
    }
    if(max-min>4)
        return false;
    return true;

}
```