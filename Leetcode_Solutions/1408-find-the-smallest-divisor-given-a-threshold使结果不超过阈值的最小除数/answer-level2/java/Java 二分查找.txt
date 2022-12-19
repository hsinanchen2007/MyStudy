### 方法一： 二分查找

#### 分析： 

- 我们记函数$cal(x)$为以$x$作为除数，数组里每个数除以$x$后的累加和
- 易知，$cal(x)$是一个单调递减的函数
- 利用$cal(x)$函数的单调性，我们可以利用二分查找的方法快速定位满足条件的最小除数

#### 算法：

- 首先设计一个函数$cal(x)$来计算以$x$为除数时的累加和（注意向上取整）
- 定义上下边界$lo$和$hi$
- 每次取区间中点作为除数$x$，对其应用函数$cal()$,取得结果$res$
- 当$res$大于$threshold$时，考虑到$cal(x)$是个单调减函数，我们应当到右区间$[mid+1, hi]$继续搜素
- 反之，我们在左区间$[lo, mid]$继续搜索，**注意mid可能是我们的所求值，不应当剔除**

#### 代码：
```java []
class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int lo = 1, hi = 1_000_000;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            // 计算以mid为除数的结果
            int res = cal(nums, mid); 
            // 1.如果这个结果数大于阀值， 说明除数mid取的太小了，我们在[mid+1, hi]中继续查找
            // 2.如果这个结果数小于等于阀值，说明除数mid取得太大，或者满足要求，我们在[lo,mid]中继续查找
            // 注意在2的情形下，mid可能是我们所要求的解，不应被剔除在搜索区间之外
            if (res > threshold) lo = mid+1;
            else                 hi = mid;

        }
        return lo;
    }
    private int cal(int[] nums, int div) {
        int sum = 0;
        for (int n : nums) {
            sum += n / div;
            // 向上取整
            if (n % div != 0) sum += 1; 
        }
        return sum;
    }
}
```

#### 复杂度分析

- 时间复杂度: $O(N*log(K))$ 其中每次调用$cal()$的时间复杂度为$N$($nums$数组的长度)，$K$为数组中的最大值，即二分查找中的右端点
- 空间复杂度:$O(1)$

