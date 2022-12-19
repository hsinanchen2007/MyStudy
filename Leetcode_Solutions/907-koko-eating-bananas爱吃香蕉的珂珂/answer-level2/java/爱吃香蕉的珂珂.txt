### 方法一：二分查找
#### 思路：
- 由于每个小时只能选择一堆香蕉，对于某个速度$K$，珂珂吃完所有香蕉花费的时间是固定的。
- 如果珂珂能以速度$K$在$H$小时内吃完这些香蕉，那么当速度大于$K$时，珂珂必然也能吃完。
- 我们可以让珂珂从速度$1$开始逐步增加速度，直到其能在$H$小时内吃完所有香蕉，此时速度$K$即是我们所要求的最小速度。
- 逐渐增加速度$K$的方法效率过低，让我们用二分查找的方法来优化它。


#### 算法：
- 定义函数$canEat(H, K)$,来判断在速度为$K$的情形下珂珂能否在$H$小时内吃完所有香蕉。我们所要做的就是一次吃完每一堆香蕉，每一堆香蕉所花费的时间为香蕉数量$Q$ $/$ $K$, 若不能整除，即有剩余，我还需要额外的一小时。 
- 用二分查找的方式，来查找这个最小速度K，如果$mid$可以完成任务，我们把查找范围缩减至$[lo, mid]$（注意不是$mid+1$,因为$mid$可能是我们所求的解），否则我们去$[mid+1, hi]$区间中继续查找，详情见代码。

```java []
class Solution {
    public int minEatingSpeed(int[] piles, int H) {
        int lo = 1, hi = Integer.MAX_VALUE;
        while (lo < hi) {
        	int mid = lo + (hi - lo) / 2;
        	if (canEat(piles, H, mid)) {
        		hi = mid;
        	} else {
        		lo = mid+1;
        	}
        }
        return lo;
    }
    private boolean canEat(int[] piles, int H, int K) {
    	int cost = 0;
    	for (int e : piles) {
    		cost += e / K;
    		if (e % K != 0) cost++; //如果不能整除，说明有剩余，多花1小时
    	}
    	return cost <= H;
    }
}
}
```
#### 复杂度分析：
- 时间复杂度：$O(NlogN)$
- 空间复杂度：$O(1)$