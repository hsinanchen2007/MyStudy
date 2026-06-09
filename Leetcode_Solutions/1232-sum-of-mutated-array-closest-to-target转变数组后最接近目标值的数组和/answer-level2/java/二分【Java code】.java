### 解题思路

### 代码

```java
class Solution {
    public int findBestValue(int[] arr, int target) {
        int left = 0;
        int right = target;
        while (left < right) {
            int mid = (left + right) >>> 1;
            int total = sum(arr, mid);

            if (total < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (Math.abs(sum(arr, left-1) - target) <= Math.abs(sum(arr, left) - target)) {
            return left-1;
        }
        return left;
    }

    public int sum(int[] arr, int n) {
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += Math.min(arr[i], n);
        }
        return sum;
    }
}
```