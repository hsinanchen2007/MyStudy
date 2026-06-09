### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
 public int nthSuperUglyNumber(int n, int[] primes) {
        if(n == 0) {
            return 0;
        }
        int[] superUgly = new int[n];
        int[] pos = new int[primes.length];
        for(int j = 0; j < primes.length; j++) {
            pos[j] = 0;
        }
        superUgly[0] = 1;
        for(int i = 1; i < n; i++) {
            int[] temp = new int[primes.length];
            int min = Integer.MAX_VALUE;
            for(int j = 0; j < primes.length; j++) {
                temp[j] = superUgly[pos[j]] * primes[j];
                if(temp[j] < min) {
                    min = temp[j];
                }
            }
            superUgly[i] = min;
            for(int k = 0; k < primes.length; k++) {
                if(min == superUgly[pos[k]] * primes[k]) {
                    pos[k]++;
                }
            }
        }
        return superUgly[n - 1];
    }
}
```