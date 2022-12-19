### 解题思路
此处撰写解题思路

### 代码

```java
//被除数越小，求出来的和越大
class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int max = Integer.MIN_VALUE;
        for (int n : nums) {
            max = Math.max(max, n);
        }
        int left = 1;
        int right = max;

        while (left < right) {
            //被除数：mid
            int mid = (left + right) >>> 1;

            int sum = 0;
            for (int n : nums) {
                // 上取整可以这样写:(p + mid - 1) / mid,记住
                sum += (n + mid - 1) / mid;
            }
            //被除数mid太小了，导致sum过大
            if (sum > threshold) {
                //下一轮区间：[mid + 1, right]
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
```