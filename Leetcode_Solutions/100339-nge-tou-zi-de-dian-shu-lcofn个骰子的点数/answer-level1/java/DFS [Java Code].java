### 解题思路
用数组记录次数 勉强AC
### 代码

```java
class Solution {
    private int[] map = new int[100];
    public double[] twoSum(int n) {
        dfs(0, n, 0);
        double total = Math.pow(6, n);
        double[] arr = new double[5 * n + 1];
        int index = 0;
        for (int i = n; i <= n * 6; i++) {
            arr[index++] = (double) map[i] / total;
        }
        return arr;
    }

    private void dfs(int sum, int n, int k) {
        if (n == k) {
            map[sum]++;
            return;
        }
        for (int i = 1; i <= 6; i++) {
            sum += i;
            dfs(sum, n, k + 1);
            sum -= i;
        }
    }
}
```