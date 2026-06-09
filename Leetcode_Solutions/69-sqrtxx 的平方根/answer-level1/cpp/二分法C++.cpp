### 解题思路
使用二分法求解，关键点是范围缩小的思路，以及结束循环的条件。

在数组算法中，我习惯于使用左闭右开的区间表达，使用left代表边界起始位置，right代表有边界的右边，所以在写经典的二分法算法中，while那里习惯写left < right，当left == right以及left >= right时，就说明区间已经缩减消失。当排除左边的范围时，写left = mid + 1，排除右边的范围时，写right = mid（因为是右开区间）。

而在该题目中有些不一样的地方是：
查找的数肯定是存在的。所以while那里怎么写都行，只要有left < right就行，不期望这里能终止算法。
除了查找到mid的平方恰好等于x，终止算法外，还需要添加另一个终止条件，那就是当范围缩小到只有两个数时，比如left=5，right=6，那么答案就在5和6之间，这是根据条件只需要取left作为结果就行。所以这里的终止条件就是mid取值之后肯定是left，就判断mid==left就可以返回mid了。

还有一个关键点是，当排除左半边时，不能写left=mid+1，因为答案还可能在mid和mid+1之间。如果让left越过了mid到了mid+1，就错过了答案。

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        int left = 0;
        int right = x;
        long long mid = 0;

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (mid == left) {
                return mid;
            }
            if (mid * mid < x) {
                left = mid;
            }else if (mid * mid > x) {
                right = mid;
            }else {
                return mid;
            }
        }
        return 0;
    }
};
```

![微信图片_20191231163902.png](https://pic.leetcode-cn.com/bc94ebc1dac24850ae8e9dd5aa6e96a457354ff25d8d5248be1a88310971a700-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191231163902.png)
