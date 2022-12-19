### 解题思路
桶排序，然后求最大公约数，如果 最大公约数 >=2,那么OK.时间复杂度O(NlogC),N是卡牌个数（相同卡牌算一个），logC是求两个数最大公约数的时间复杂度，总共需要比较 N-1次

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        if (deck.length < 2) {
            return false;
        }
        int[] temp = new int[10000];
        for (int i : deck) {
            temp[i]++;
        }
        int gcd = -1;
        for (int i=0; i<10000; i++) {
            if (temp[i] > 0) {
                if (gcd == -1) {
                    gcd = temp[i];
                } else {
                    gcd = getGcd(gcd, temp[i]);
                }
            }
        }
        return gcd >=2;
    }
    private int getGcd(int a, int b) {
        while (a != 0) {
            int temp = b%a;
            b=a;
            a=temp;
        }
        return b;
    }
}
```