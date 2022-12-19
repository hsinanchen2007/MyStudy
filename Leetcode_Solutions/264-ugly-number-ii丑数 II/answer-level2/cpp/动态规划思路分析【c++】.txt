动态规划其实本身并不复杂，比较难的点在于，有时候有些思维习惯没养成。
所以，这里重点的分析在于如何快速培养这个思维习惯。

这里的很多解答对思路的分析实在是太浅了，甚至有些看着就像是看了答案反推的。

这里就是直接套我的动态规划两步走

```
第一步，先提出自底部向上的方案———无论题目怎么变换，动态规划都是要老老实实一步步遍历数据
    在遍历数据方面，是正常的动态规划，从头遍历到尾
    这道题的核心难点在于当前的值跟前几步，而不是前一步有关。
    最简单的思路，寻找第k个，之前的k-1个数分别跟2,3,5相乘，然后找到比k-1大，且最小的数。
    如何优化？减少存储和计算次数？
```
```
第二步，优化当前方案——存储的上1/N步的重要信息是否找对了
    可以观察到，如果2*nums[x]为第k个最小的值，那么k+1个数，需要考虑2*nums[x + 1]而不是2*nums[x]
    这样的话，其实我就不啰嗦了，需要存储什么数据就很清晰了
```
代码如下
```
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 0) {
            return 0;
        }
        vector<int> nums(n);
        nums[0] = 1;
        int index_2 = 0;
        int index_3 = 0;
        int index_5 = 0;
        for (int i = 1; i < n; ++i) {
            int multi_2 = 2 * nums[index_2];
            int temp_min = multi_2;
            int multi_3 = 3 * nums[index_3];
            temp_min = min(multi_3, temp_min);
            int multi_5 = 5 * nums[index_5];
            temp_min = min(multi_5, temp_min);         
            nums[i] = temp_min;
            if (temp_min == multi_2) {
                ++index_2;
            }
            if (temp_min == multi_3) {
                ++index_3;
            }
            if (temp_min == multi_5) {
                ++index_5;
            }
        }
        return nums[n - 1];
    }
};
```
