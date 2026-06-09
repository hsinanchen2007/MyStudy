第一次用，没有人认真做，花了一些琐碎的时间摸索，一直确认自己思路没问题，也不知道为什么一直提交都报错，最后是returnSize这个参数是有作用的，如果不赋值，那么就不能好好运行。不过也不是什么大问题。
这种算法思路是最简单的，但是是最费时间的，所以，还是用Hash表比较快。
```
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
int i,j;
int *a;

    for(i = 0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if( ( nums[i] + nums[j] ) == target){
                if( i != j ){
                    a = (int *)malloc(sizeof(int) * 2);
                    *a   =  i;
                    a[1] =  j;
                    *returnSize = 2;
                    return a;
                } 
            }
        }
    } 
*returnSize = 0;
return a;
}
```
