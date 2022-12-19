代码思路和官方方法二一致，求多个数的最大公约数

代码实现上，利用java stream的特性，将代码行数压缩

```
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int[] cnt = new int[10010];
        for(int i: deck) cnt[i] ++;
        return Arrays.stream(cnt).filter(x -> x > 0).reduce((a, b) -> getGCD(a, b)).getAsInt() > 1;
    }
    
    public int getGCD(int a, int b) {
        if (b == 0) { return a; }
        else { return getGCD(b, a%b); }
    }
}
```
