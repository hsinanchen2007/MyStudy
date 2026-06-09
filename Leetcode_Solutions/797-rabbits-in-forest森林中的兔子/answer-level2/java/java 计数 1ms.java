回答为a=0，则res++；
回答为a>0，则最多有a+1只兔子同一颜色，满足count[a] % (a + 1) == 0，res+=a+1；
```java
class Solution {
    public int numRabbits(int[] answers) {
        int res = 0;
        int[] count = new int[1000];
        for (int a : answers) {
            if (count[a] % (a + 1) == 0) res += a + 1;
            count[a]++;
        }
        return res;
    }
}
```
