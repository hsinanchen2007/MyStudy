#### 解题思路
一个挺笨的办法，从左到右扫描凹槽，扫描到了就把他们填平。此步骤的复杂度为 O(N)。
整个数据扫描完以后再次扫描，直到把能接雨水的凹槽全部填平。

时间复杂度为： $O(kN)$ （k为所有凹槽里最大的填平次数）
最终提交的时间还行，2 ms

#### 代码
```java
class Solution {
    public int trap(int[] height) {
        int trapWater = 0;
        int curWater = trapWaterPerRound(height);
        while (curWater > 0) {
            trapWater += curWater;
            curWater = trapWaterPerRound(height);
        }
        return trapWater;
    }

    private int trapWaterPerRound(int[] height) {
        int trapWater = 0;
        int i = 0;
        int j = 0;
        while(j < height.length) {
            while (j < height.length-1 && height[j] > height[j+1]) {
                ++ j;
            }
            while (j < height.length-1 && height[j] <= height[j+1]) {
                ++j;
            }
            int curWater = trapWaterPerHollow(height, i, j);
            // System.out.println(i + ", " + j + ": " + curWater);
            trapWater += curWater;
            i = j;
            j = i + 1;
        }
        return trapWater;
    }

    private int trapWaterPerHollow(int[] height, int i, int j) {
        if (j - i == 1) return 0;
        int water = 0;
        int border = Math.min(height[i], height[j]);
        for (int k = i+1; k < j; ++k) {
            // System.out.println(border + ", " + k + ":" + height[k]);
            if (height[k] >= border) continue;
            water += border - height[k];
            // 填平
            height[k] = border;
        }
        return water;
    }
}
```
