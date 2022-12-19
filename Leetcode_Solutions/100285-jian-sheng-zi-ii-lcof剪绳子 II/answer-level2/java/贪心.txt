### 解题思路
刚想说dp更好，马上逼我用贪心，其实就是找规律，会发现，大于4的数坑定会拆分出尽可能多的3，或者拆出若干个3和两个2，所以，找3的个数就行了

### 代码

```java
class Solution {
    public int cuttingRope(int n) {
        if (n == 1) return 1;
        if (n == 2) return 1;
        if (n == 3) return 2;
        long res = 1;
        while (n > 4) {
            res *= 3;
            n -= 3;
            res %= (1e9 + 7);
        }
        return (int)(res * n % (1e9 + 7));
    }
}
```