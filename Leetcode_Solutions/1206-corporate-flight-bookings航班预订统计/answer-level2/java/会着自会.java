### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] results = new int[n + 1];
        for (int i = 0; i < bookings.length; i++) {
            int[] values = bookings[i];
            int begin = values[0];
            int end = values[1];
            for (int j = begin; j <= end; j++) {
                results[j] += values[2];
            }
        }
        return Arrays.copyOfRange(results, 1, results.length);
    }
}
```