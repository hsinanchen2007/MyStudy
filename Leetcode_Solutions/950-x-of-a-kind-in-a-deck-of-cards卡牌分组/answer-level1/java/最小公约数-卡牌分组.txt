思路很简单：用数组存每个数出现的次数，然后求相邻的数的最小公约数，再拿该公倍数去和下一个数去求最小公约数，当公约数小于2的时候，直接返回false;
最小公约数这里采用辗转相除法gcd。
```
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int count[] = new int[10000];
        if(deck.length <= 1)    return false;
        for(int i = 0; i < deck.length; i++){
            count[deck[i]]++;
        }
        int flag = 0, num = 0;
        for(int i = 0 ; i < 10000; i++){
            if(count[i]!=0){
                if(flag == 0){
                    flag = 1;
                    num = count[i];
                }
                else{
                    num = gcd(num, count[i]);
                    if(num < 2)
                        return false;
                }
            }
        }
        return true;
    }
    private int gcd(int a, int b){
        int x = Math.max(a, b);
        int y = a + b - x;
        int z = x % y;
        return z==0 ? y: gcd(y, z);
    }
}
```
