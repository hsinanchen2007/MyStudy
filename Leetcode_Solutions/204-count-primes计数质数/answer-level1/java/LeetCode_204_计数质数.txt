### 解题思路

- 厄拉多塞筛法
比如说求20以内质数的个数,首先0,1不是质数.2是第一个质数,然后把20以内所有2的倍数划去.2后面紧跟的数即为下一个质数3,然后把3所有的倍数划去.3后面紧跟的数即为下一个质数5,再把5所有的倍数划去.以此类推.

### 代码

```java
class Solution {
    public int countPrimes(int n) {
        boolean[] isPrimes = new boolean[n + 1];
        Arrays.fill(isPrimes, true);
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrimes[i]) {
                count++;
                for (int j = 2; j * i <= n; j++) {
                    isPrimes[i * j] = false;
                }
            }
        }
        return count;
    }
}
```