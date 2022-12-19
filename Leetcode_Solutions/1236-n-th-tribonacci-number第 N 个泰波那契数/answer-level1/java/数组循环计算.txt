```
class Solution {
    public int tribonacci(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 1;
        } else {
            int[] array = new int[] {0, 1, 1};
            for (int i = 3; i <= n; i++) {
                array[i % 3] = array[0] + array[1] + array[2];
            }
            return array[n % 3];
        }
    }
}
```