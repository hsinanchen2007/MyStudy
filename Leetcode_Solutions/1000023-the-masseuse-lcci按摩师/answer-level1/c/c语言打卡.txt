### 解题思路
显然，可以用动态规划求解。设$f(n)$为接收第$n$个预约时的最优分钟数，则状态转移方程为$f(n)=\max\limits_{1\leqslant i\leqslant n-2}f(i)+t_n$，且$f(1)=t_1$，$f(2)=\max \{t_1,t_2\}$，采用写备忘录自底向上方法循环可以得到，最后结果为$\max \{f(n-1), f(n)\}$。
同时，可以优化一下额外存储空间。显然，$\max\limits_{1\leqslant i\leqslant n-2}f(i)=\max \{f(n-3),f(n-2)\}$，所以我们可以只记录最近的三个函数值，最后的时间复杂度为$O(n)$，空间复杂度为$O(1)$

### 代码

```c
int massage(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    else if(numsSize == 1)
        return nums[0];
    else if(numsSize == 2)
        return (nums[0] > nums[1] ? nums[0] : nums[1]);
    int i, current, memorize[3];
    memorize[0] = (numsSize > 0 ? nums[0] : 0);
    memorize[1] = (numsSize > 1 ? nums[1] : 0);
    memorize[2] = (numsSize > 2 ? nums[2] + nums[0] : 0);
    current = memorize[2];
    for(i = 3;i < numsSize;i ++){
        current = nums[i] + (memorize[0] > memorize[1] ? memorize[0] : memorize[1]);
        memorize[0] = memorize[1];
        memorize[1] = memorize[2];
        memorize[2] = current;
    }
    return (memorize[1] > memorize[2] ? memorize[1] : memorize[2]);
}
```