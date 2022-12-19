### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int trap(int[] height) {
        if (height.length <= 1) {
            return 0;
        }
        int n = height.length - 1;
        int slowP = 0;
        int fastP = 1;
        int sum = 0;

        while (slowP < n) {
            // 左指针小于右指针
            while (slowP < n - 1 && height[slowP] <= height[fastP]) {
                slowP++;
                fastP = slowP + 1;
            }

            // 左指针确定
            int slowHeight = height[slowP];
            int maxP = fastP;

            // 往下确定右指针
            while (fastP < n
                    && height[fastP] < slowHeight) {
                fastP++;
                maxP = height[fastP] >= height[maxP] ? fastP : maxP;
            }

            // 相当于慢指针后面的数永远比慢指针小
            if (fastP == n) {
                fastP = maxP;
            }

            int heightMin = Math.min(slowHeight, height[fastP]);

            for (int i = slowP + 1; i < fastP; i++) {
                sum += Math.max(heightMin - height[i], 0);
            }

            slowP = fastP;
            fastP = slowP + 1;
        }

        return sum;
    }
}
```