由于速度是一个有范围的整数，因此可以使用二分查找法解决这个问题。

思路：

1、速度越小，耗时越多；
2、搜索的是速度。因为题目限制了珂珂一个小时之内只能选择一堆香蕉吃，因此速度最大值就是这几堆香蕉中，数量最多的那一堆。速度的最小值是 1（其实还可以再分析一下下界是多少）；

3、还是因为珂珂一个小时之内只能选择一堆香蕉吃，因此：**每堆香蕉吃完的耗时 = 这堆香蕉的数量 / 珂珂一小时吃香蕉的数量**，这里的 `/` 在不能整除的时候，需要上取整。


**参考代码 1：**

```Java []
public class Solution {

    public int minEatingSpeed(int[] piles, int H) {
        int maxVal = 1;
        for (int pile : piles) {
            maxVal = Math.max(maxVal, pile);
        }

        // 速度最小的时候，耗时最长
        int left = 1;
        // 速度最大的时候，耗时最短
        int right = maxVal;

        while (left < right) {
            int mid = (left + right) >>> 1;

            if (calculateSum(piles, mid) > H) {
                // 耗时太多，说明速度太慢了，下一轮搜索区间在
                // [mid + 1, right]
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    /**
     * 如果返回的小时数严格大于 H，就不符合题意
     *
     * @param piles
     * @param speed
     * @return 需要的小时数
     */
    private int calculateSum(int[] piles, int speed) {
        int sum = 0;
        for (int pile : piles) {

            // 上取整可以这样写
            sum += (pile + speed - 1) / speed;

        }
        return sum;
    }
}
```
```Python []
from typing import List


class Solution:
    def minEatingSpeed(self, piles: List[int], H: int) -> int:
        left = 1
        right = max(piles)

        while left < right:
            mid = (left + right) >> 1

            if self.__calculate_sum(piles, mid) > H:
                left = mid + 1
            else:
                right = mid
        return left

    def __calculate_sum(self, piles, speed):
        res = 0
        for pile in piles:
            res += (pile + speed - 1) // speed
        return res
```

**补充**：上取整还可以这样写：`sum += (pile + speed - 1) / speed;`。

```Java []
/**
 * 如果返回的小时数严格大于 H，就不符合题意
 *
 * @param piles
 * @param speed
 * @return 需要的小时数
 */
private int function(int[] piles, int speed) {
    int sum = 0;
    for (int pile : piles) {
        // 上取整可以这样写
        sum += (pile + speed - 1) / speed;
    }
    return sum;
}
```
```C++ []
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int calculateSum(vector<int> &piles, int speed) {
        int sum = 0;
        for (int pile : piles) {
            sum += (pile + speed - 1) / speed;
        }
        return sum;
    }

public:
    int minEatingSpeed(vector<int> &piles, int H) {
        int maxVal = 1;
        for (int pile : piles) {
            maxVal = max(maxVal, pile);
        }

        // 速度最小的时候，耗时最长
        int left = 1;
        // 速度最大的时候，耗时最短
        int right = maxVal;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (calculateSum(piles, mid) > H) {
                // 耗时太多，说明速度太慢了，下一轮搜索区间在
                // [mid + 1, right]
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
```


**复杂度分析**：

+ 时间复杂度：$O(N \log \max(piles))$，这里 $N$ 表示数组 `piles` 的长度；
+ 空间复杂度：$O(1)$。