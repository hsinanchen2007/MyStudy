### 解题思路
暴力解超时，最小堆的时间耗时有点大，动态规划果然还是最优的。其他人关于动态规划的解释已经很多了，给一幅图就能很清楚地明白动态规划的过程。

UglyNumber_mutiply2[index2]：  1x2    2x2    3x2    4x2...
UglyNumber_mutiply3[index3]：  1x3    2x3    3x3    4x4...
UglyNumber_mutiply5[index5]：  1x5    2x5    3x5    4x5...

### 代码

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;

        int* UglyNum = new int[n];
        int index2 = 0, index3 = 0, index5 = 0;
        UglyNum[0] = 1;

        for (int i = 1; i < n; i++) {
            int num2 = 2 * UglyNum[index2];
            int num3 = 3 * UglyNum[index3];
            int num5 = 5 * UglyNum[index5];
            int nextUglyNum = min(num2, min(num3, num5));

            UglyNum[i] = nextUglyNum;
            //用if是为了跳过重复的值
            if (nextUglyNum == num2) index2++;
            if (nextUglyNum == num3) index3++;
            if (nextUglyNum == num5) index5++;
        }

        return UglyNum[n - 1];

    }
};
```