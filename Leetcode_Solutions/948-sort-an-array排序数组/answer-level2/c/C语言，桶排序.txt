### 解题思路
今天又是桶排序牛逼的一天。
先建立一个100001大的数组t，全部初始化为0.
遍历目标数组，把t的第nums[i]加上50000位+1.
加50000是因为nums[i]属于[-50000,50000]，而数组下标没有负数。
之后遍历数组t，当t[i]不为0时，ans[j++]等于i+50000就行了。
最后返回答案数组ans。
（没想到需要建立并且遍历100001这么大的数组还能时间超80+，内存100。。。）

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int t[100001]={0};                              //建立空桶
    for(int i=0;i<numsSize;i++){
        ++t[nums[i]+50000];                         //向桶里加旗子
    }
    int* ans=(int*)malloc(sizeof(int)*numsSize);
    int j =0;
    for(int i=0;i<100001;i++){
        while(t[i]>0){
            ans[j++] = i-50000;
            --t[i];                                 // 当桶子里有旗子时拔出，直到没有旗子为止
        }
    }
    return ans;
}
```