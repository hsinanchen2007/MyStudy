### 解题思路
用新数组来顺序记录排好序的数组

### 代码

```c
void rotate(int* nums, int numsSize, int k){
    //解题思路
    //数组移动k轮
    //设一临时变量t来保存数组变量的临时值，然后交换位置
    //从高位取低一位的值
    /*for(int i = 0; i < k; i++){
        int t = nums[numsSize - 1];
        for(int j = numsSize - 1; j > 0; j--){
            nums[j] = nums[j - 1];
        }
        nums[0] = t;
    }*/

    //相对k轮来说，直接移动k位时间更少
    //从高位到低位循环移动的话，高位的原值会被覆盖，需要更多的存储空间
    /*int t = nums[numsSize - 1];//6
    int m;
    for(int i = (numsSize - 1 + k) % numsSize; i < numsSize; i = (i + k) % numsSize){
        //nums[i] = t;
        t = nums[i];
        nums[i] = nums[(i - k + numsSize) % numsSize];
        nums[(i + k) % numsSize] = t;
    }*/

    //参考别人的思路
    //用新数组来顺序记录排好序的数组

    int *res = (int *)malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++){
        res[i] = nums[(i - k%numsSize + numsSize) % numsSize];
    }
    memcpy(nums, res, numsSize*sizeof(int));
    free(res);


}
```