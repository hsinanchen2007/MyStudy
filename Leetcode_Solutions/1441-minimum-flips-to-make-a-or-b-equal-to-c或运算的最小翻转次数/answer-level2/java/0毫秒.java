### 解题思路
我们先从1位二进制数的角度看下需要进行多少次翻转才能使当前位上的 a|b == c
a   b   c  翻转次数
0   0   0     0
0   0   1     1
0   1   0     1
0   1   1     0
1   0   0     1
1   0   1     0
1   1   0     2
1   1   1     0

可以很清楚的看到，一共分为三种情况：
（1）当前位上a|b == c，所以无需翻转操作
（2）当前位上a == 1，b == 1， c == 0，需要进行2次翻转操作
（3）剩余的情况就只需要进行1位翻转操作

综上，为了使得数字a|b == c，只需要从低位到高位依次遍历，然后判断该位上需要进行几次翻转，最后求和即可
### 代码

```java
class Solution {
    public int minFlips(int a, int b, int c) {
        if((a | b) == c){
            return 0;
        }
        int res = 0;
        for(int i = 0; i <= 31; i++){
            int checkc = 1 & (c >> i);
            int checka = 1 & (a >> i);
            int checkb = 1 & (b >> i);
            if((checka | checkb) == checkc){
                continue;
            }else if(checka == 1 && checkb == 1 && checkc == 0){
                res += 2;
            }else{
                res += 1;
            }
        }
        return res;
    }
}
```