

第一步：【把冰箱门打开】 申明一个数组s[32], 并初始化为0。

第二步：【把大象放进去】 将nums里面的每一个num二进制分解，将对应的位放入s[32]数组

第三步：【把冰箱门关上】 s[32]就是最终需要的解，转换为int类型输出。

*时间复杂度：O(32N) ->对输入数组遍历一遍为N，对每个元素有取位的32次运算，故结果为32N。

*空间复杂度：O(32)  ->额外的空间，就是我们申请的数组s[32]。当然，可进一步优化为char类型，或者为bit:2类型。


```
int singleNumber(int* nums, int numsSize){
    int s[32] = {0}; // 32 = sizeof(int)
    int i, j;
        
    for(i = 0; i < numsSize; i++) {     
        for (j = 0; j < 32; j++) {
            s[j] += (((unsigned int)nums[i])>>j) % 2;
            if(s[j] == 3) 
                s[j] = 0;
        }
    }

    int res = s[0];
    unsigned int tag = 1;
       
    for(j = 0; j < 32; j++) {
        if(s[j])
            res |= tag<<j;
    }

    return res;
}
```




