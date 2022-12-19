### 解题思路
求count[i]的最大公约数
Time O(N*logC)N为卡牌个数，logC为求两个数的最大公约数的时间复杂度
Space O(N + C)

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int len = deck.length;
        if(len < 2)
            return false;
        int[] count = new int[10000];
        for(int i = 0; i < len; i++)
            count[deck[i]]++;
        int g = -1;
        for(int i = 0; i < 1000; i++){
            if(count[i] == 1)
                return false;
            if(count[i] > 1){
                if(g == -1){
                    g = count[i];
                }else{
                    g = gcd(g, count[i]);
                }
            }
        }
        return g >= 2;
    }
    public int gcd(int n, int m){
        return m == 0 ? n : gcd(m, n % m);
    }
}
```