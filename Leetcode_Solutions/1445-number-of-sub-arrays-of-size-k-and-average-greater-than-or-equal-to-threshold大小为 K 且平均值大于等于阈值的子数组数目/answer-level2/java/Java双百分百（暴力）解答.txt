比较滑稽的是子数组一定是连续的。一下子难度下降不少。

### 代码

```java
class Solution {
    public static int numOfSubarrays(int[] arr, int k, int threshold) {
        int ans = 0;
        int length = arr.length;

        for (int i = 0; i <= length - k; i++) {
            int sum = 0;
            for (int j = i; j < i + k; j++) {
                sum += arr[j];
            }
            if (sum >= k * threshold) {
                ans++;
            }
        }

        return ans;
    }
}
```