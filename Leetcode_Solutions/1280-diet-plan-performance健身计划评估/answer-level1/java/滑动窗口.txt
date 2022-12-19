```java
class Solution {
    public int dietPlanPerformance(int[] calories, int k, int lower, int upper) {
        // 总分
        int totalScore = 0;
        // 当前 window 的总能量
        int windowTotalCalories = 0;

        // 维护滑动窗口
        int left = 0;
        int right = 0;
        while (right < calories.length) {
            // 更新当前窗口的总能量
            windowTotalCalories += calories[right];
            
            // left 的移动时机：窗口大小为 k 的时候
            // left 的移动策略： 
            //  1. 判断窗口中的总卡路里并且和 lower 以及 upper 比较，来确定总分
            //  2. 移动 left 的时候，减去 left 指定的卡路里数量
            if (right - left + 1 == k) {
                if (windowTotalCalories < lower) {
                    totalScore--;
                } else if (windowTotalCalories > upper) {
                    totalScore++;
                }
                windowTotalCalories -= calories[left++];
            }

            right++;
        }
        return totalScore;
    }
}
```