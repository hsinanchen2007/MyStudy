### 解题思路
学会了欧几里得算法的递归写法

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int[] t = new int[10000];
        for (int i = 0 ; i < deck.length; i++) {
            t[deck[i]]++;
        }
        int g = -1;
        for (int i = 0; i < 10000; i++) {
            if (g == -1 && t[i] != 0) g = t[i];
            if (t[i] != 0) {
                g = gcd(g, t[i]);
            }
        }
        return g >= 2;
    }

    int gcd(int x, int y) {
        return x == 0 ? y : gcd(y % x, x); 
    }
}
```