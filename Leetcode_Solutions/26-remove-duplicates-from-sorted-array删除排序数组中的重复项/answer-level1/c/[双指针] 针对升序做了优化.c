主要针对序列做了优化，比如
1,2,3,4,5,6,7,8

代码如下：
```
int removeDuplicates(int *nums, const int numsSize)
{
        if (numsSize == 0) return 0;
 
        int n_base = 0; 
        int n_move = 0;
 
        for (n_move=1; n_move<numsSize; n_move++) {
                if (nums[n_base] != nums[n_move]) {
                        if (n_move - n_base > 1)  // 思考了下，这里加个判断，如果是紧邻的升序，这里就不用复制了
                                nums[n_base+1] = nums[n_move];
                        n_base++;
                }
        }
 
        return (n_base+1);
}
```
