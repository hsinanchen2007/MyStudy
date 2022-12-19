### 解题思路
分两个步骤：
第一步，统计每个整数出现的次数（用int[10000]比HashMap快很多）
第二步，求所有出现次数的最大公约数，如果这个数不小于2，true

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int[] counts = new int[10000];
        for(int card : deck) {
            counts[card]++;
        }
        int gcd = counts[deck[0]];
        for(int cnt : counts) {
            if(cnt != 0) {
                gcd = getGCD(gcd, cnt);
                if(gcd < 2) {
                    return false;
                }
            }
        }
        return true;
    }

    public int getGCD(int a, int b) {
        return a % b == 0 ? b : getGCD(b, a % b);
    }
}
```