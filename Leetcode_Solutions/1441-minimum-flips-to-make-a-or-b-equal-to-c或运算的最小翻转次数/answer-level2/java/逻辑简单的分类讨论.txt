### 解题思路
将该问题分成两个子问题来解决，第一个子问题是如何获取十进制数字的二进制表示下每位的数字，第二个子问题是如何将a,b,c每位数字进行比较并确定是否需要反转。
我们首先从最简单的情形考虑，即a与b按位或的结果即为c，这种情况下不需要对a,b的某位进行反转，直接返回0。
接下来自然想到使用循环结构，由于不确定循环次数，显然需要使用`while`循环。每次循环中我们使用`x & 1`来获取最低位数字，使用`x >> 1`来进行减半除法。鉴于每次循环内部的处理，当满足条件`a | b == c`的时候我们跳出循环。
下面考虑a,b,c每一位tmp_a,tmp_b和tmp_c对应的情况。我们分成`tmp_c == 0`和`tmp_c == 1`讨论。
* `tmp_c == 0`时，必须满足`tmp_a == 0 && tmp_b == 0`，该情况下不执行任何语句；如果tmp_a和tmp_b有一个是1，则需要反转一次，将count自加1；如果二者全为1，则需要反转两次，将count加2。
* `tmp_c == 1`时，tmp_a，tmp_b只要有一个为1则无需反转。只有二者皆为0时，需要反转一次，count自加1。

### 代码

```java
class Solution {
    public static int minFlips(int a, int b, int c) {
        int count = 0;
        if((a|b) == c){
            return 0;
        }
        else{
            while((a|b) != c){
                int tmp_a = (a == 0) ? 0 : a & 1;
                int tmp_b = (b == 0) ? 0 : b & 1;
                int tmp_c = (c == 0) ? 0 : c & 1;
                if(tmp_c == 1){
                    // 如果a或b中至少有一个为1，该位置不需要反转
                    if(tmp_a == 1 || tmp_b == 1 || (tmp_a == 1 && tmp_b == 1)){
                        ;
                    }
                    else{
                        count++;
                    }
                }
                else{
                    if(tmp_a == 1 && tmp_b == 1){
                        count = count + 2;
                    }
                    else if(tmp_a == 0 && tmp_b == 0){
                        ;
                    }
                    else{
                        count++;
                    }
                }
                a = a >> 1;
                b = b >> 1;
                c = c >> 1;
            }
        }
        return count;
    }
}
```