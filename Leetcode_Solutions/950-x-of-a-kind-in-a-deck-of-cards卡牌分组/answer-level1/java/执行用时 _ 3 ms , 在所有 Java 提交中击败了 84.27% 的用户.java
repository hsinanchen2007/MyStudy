
```
class Solution {
    // 卡牌分组————最大公约数
    public boolean hasGroupsSizeX(int[] deck) {
        int[] arr = new int[10001];
        for(int d : deck) arr[d]++;
        int x = -1;
        for(int a : arr){
            if (a == 0) continue;
            if (x == -1) x = a;
            else x = gcd(x, a);                 
            if (x == 1) return false;
        }
        return x >= 2;
    }
    private int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
