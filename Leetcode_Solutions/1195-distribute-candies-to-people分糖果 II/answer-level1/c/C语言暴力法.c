### 解题思路
总结：
1. 错把returnSize当成了要返回的数组。
2. 学习了memset对数组/结构体的清空。
3. 没看到for语句的i++，语句内还对i进行了++。（粗心）

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int* res = (int*)malloc(num_people*sizeof(int));
    memset(res, 0, sizeof(int)*num_people);     //用于初始化res
    *returnSize = num_people;
    for(int i=0;candies>0;i++){         //candies表剩余总糖果,i+1表本次本应分配数
        if (i+1<=candies) {   //糖果够用
            res[i%num_people]+=i+1;
            candies-=i+1;
        }else{                //糖果最后一次分配不足
            res[i%num_people]+=candies;
            candies=0;
        }
    }
    return res;
}
```
不过从提交结果上看，暴力求解法好像从执行的时间和内存消耗都不是很好。