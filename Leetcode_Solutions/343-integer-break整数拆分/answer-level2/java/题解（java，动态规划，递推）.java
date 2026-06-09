基本思路：

对于一个正整数n，可以先找出将其分为两个数a,b的和的所有情况。
对于每一种情况，都会有一个最有解，可能是这两个数的积a*b。
或者是将a分解后可能获得的最大的乘积（存储在map中）比a大，那么用那个值替换a，b同理。
再在所有的两两组合中找出最大值max，将（n,max）存入map中。

```
/*
2 -> 1
3 -> 2
4 -> 4
5 -> 6 
6 -> 9
7 -> 12
8 -> 18
9 -> 27
10 -> 36
*/

class Solution {
    public int integerBreak(int n) {
        //初始化map
        Map<Integer,Integer> map = new HashMap<>();
        map.put(1,1);
        //定义临时变量
        int max = 0;
        int num1 = 0;
        int num2 = 0;
        //从2遍历到n
        int m = 2;
        while(m <= n) {
            for(int i = 1; i <= m/2; i ++) {
                num1 = i;
                num2 = m - i;
                //如果分解num1或num2能获得更大的乘积，则替换掉num1或num2
                num1 = map.get(num1) > num1 ? map.get(num1) : num1;
                num2 = map.get(num2) > num2 ? map.get(num2) : num2;
                //更新最大值
                max = num1 * num2 > max ? num1 * num2 : max;
            }
            //加入map
            map.put(m,max);
            m ++;
        }
        return map.get(n);
    }
}
```
