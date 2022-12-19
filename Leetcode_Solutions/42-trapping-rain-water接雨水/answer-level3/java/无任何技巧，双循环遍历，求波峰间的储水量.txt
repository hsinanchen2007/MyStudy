### 解题思路
```text
1. 增加一个辅助函数，记录两个波峰间的储水量
2. 第二个波峰为大于等于第一个波峰或与第一个波峰偏差量最小的波峰（遍历整个数组，得到和第一个波峰偏差量最小的波峰）
3. 波峰间的储水量求和
注：两个波峰，不一定是两个相邻波峰，第二个波峰满足的条件见步骤2。对应测试用例：{5,2,1,2,1,5}
```
### 代码

```java
class Solution {
    public int trap(int[] height) {
        // 边界条件处理，如果小于2根柱子，则无法储存雨水
        if (height.length < 2) {
            return 0;
        }
        // 能够接雨水的总量
        int sum = 0;
        // 遍历高度，找到相邻的两个波峰，雨水只在两个相邻的波峰之间
        int peak1 = 0;
        int peak1Index = 0;
        int peak2 = 0;
        int peak2Index = 0;
        // 考虑边界条件的波峰
        for (int i = 0; i < height.length;) {
            if (isPeak(height, i)) {
                peak1 = height[i];
                peak1Index = i;
                // 遍历，寻找下一个波峰或遍历到最小值，寻找最小偏差
                int minOffset = Integer.MAX_VALUE;
                // 记录下一个波峰是否存在，存在返回true，不存在为false
                boolean peakFlag = false;
                // int minOffsetIndex = 0;
                for (int j = i + 1; j < height.length; j++) {
                    if (isPeak(height, j)) {
                        peakFlag = true;
                        // 更新偏差，如果偏差大于0，则计算储水量，如果偏差都小于0，则根据最小偏差记录出水量
                        // 如果遍历到另一个波峰比前一个波峰大，则计算储水量，停止遍历
                        if (height[j] >= peak1) {
                            peak2Index = j;
                            int tmpCapacity = calcCapacity(peak1, height[peak2Index], peak1Index, peak2Index, height);
                            sum += tmpCapacity;
                            i = j;
                            // 找到比初始波峰高的位置，偏移量重新恢复为最大值
                            minOffset = Integer.MAX_VALUE;
                            break;
                        }
                        if (height[j] < peak1) {
                            if (peak1 - height[j] < minOffset) {
                                minOffset = peak1 - height[j];
                                peak2Index = j;
                            }
                        }
                    }
                }
                if (minOffset != Integer.MAX_VALUE) {
                    int tmpCapacity = calcCapacity(peak1, height[peak2Index], peak1Index, peak2Index, height);
                    sum += tmpCapacity;
                    i = peak2Index;
                }
                // 如果不存在下一个波峰，则停止
                if (!peakFlag) {
                    break;
                }
            } else {
                // 不是顶点，i++，继续向下遍历
                i++;
            }
        }
        return sum;
    }

    // 计算波峰
    private boolean isPeak(int[] height, int i) {
        // 用例出错1：未考虑开头和结尾为波峰的边界条件
        if (i == 0) {
            if (height[i] > height[i + 1]) {
                return true;
            } else {
                return false;
            }
        }

        if (i == height.length - 1) {
            if (height[i] > height[i - 1]) {
                return true;
            } else {
                return false;
            }
        }
        if ((height[i] > height[i - 1] && height[i] >= height[i + 1]) ||
                (height[i] >= height[i - 1] && height[i] > height[i + 1])) {
            return true;
        }
        return false;
    }

    // 找到两个相邻的波峰，计算着两个相邻的波峰可以储存的雨水量
    private int calcCapacity(int peak1, int peak2, int peak1Index, int peak2Index, int[] height) {
        // 获取较小的peak
        int minPeak = Math.min(peak1, peak2);
        // 木桶原理，以较小的波峰计算出高度总和，最后加上大波峰的值（一个trick，最后遍历时会减去）
        int sum = minPeak * (peak2Index - peak1Index + 1);
        for (int i = peak1Index; i <= peak2Index; i++) {
            // 用例出错2：如果高度大于小的波峰，则减去小的波峰
            if (height[i] >= minPeak) {
                sum -= minPeak;
                continue;
            }
            sum -= height[i];
        }
        return sum;
    }
}
```

### 测试用例
```java
public class SolutionTest {
    Solution solution = new Solution();

    @Test
    public void trap() {
        int[] input1 = {0,1,0,2,1,0,1,3,2,1,2,1};
        int expect1 = 6;
        int result1 = solution.trap(input1);
        assertEquals(expect1, result1);

        // 出错用例2
        int[] input2 = {2,0,2};
        int expect2 = 2;
        int result2 = solution.trap(input2);
        assertEquals(expect2, result2);

        // 出错用例3
        int[] input3 = {5,4,1,2};
        int expect3 = 1;
        int result3 = solution.trap(input3);
        assertEquals(expect3, result3);

        // 出错用例4
        int[] input4 = {5,2,1,2,1,5};
        int expect4 = 14;
        int result4 = solution.trap(input4);
        assertEquals(expect4, result4);
    }
}
```