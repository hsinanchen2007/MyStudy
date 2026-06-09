```
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] trip = new int[1001];
        for (int[] step : trips) {
            trip[step[1]] += step[0];
            trip[step[2]] -= step[0];
        }
        int n = 0;
        for (int num : trip) {
            n += num;
            if (n > capacity) {
                return false;
            }
        }
        return true;
    }
}
```
