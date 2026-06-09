### 解题思路
公约数

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        if (deck == null || deck.length < 2) {
            return false;
        }
        int[] count = new int[10000];
        for (int num : deck) {
            count[num]++;
        }
        int g = count[deck[0]];
        for (int num : count) {
            g = gcd(g, num);
        }
        return g >= 2;
    }
    private int gcd(int x, int y) {
        return (x == 0) ? y : gcd(y % x, x);
    }
}
```