**思路**
先随便画一个Z字找规律：

R/C     1   2   3   4   5   6   7

0       A           G           M
1       B       F   H       L   N
2       C   E       I   K   
3       D           J

先观察Z字走向，发现列1，4，7之间的距离都是固定的（称这些列的字符为正常字符），而两列之间存在插入的字符（称插入字符），如E F K L。由此想到用状态+距离解决。

有两种状态：
第一种：下一个字符属于插入的字符；
第二种：下一个字符属于正常的字符。
用一个boolean型变量insert表示状态。

以 0 ~ rowNumbers-1 之间的字符（A B C D）为距离计算的基础，用for遍历A B C D这一列，for中用while遍历行。
如果下一个字符是要插入的字符，则insert = true，否则为false，并以此为距离计算的依据。
因为插入之后若不换行则下一个必然是正常字符，所以通过true和false的反复切换，计算距离并逐个将字符用append方法写入StringBuilder对象。

**代码**
以下是AC代码，时间超过78.44，内存超过86.91，对我这个新人来说勉强可以接受。
```java
class Solution {
    public String convert(String s, int numRows) {
        if(numRows == 1) {      //特判，减少时间内存消耗
            return s;
        }
        int p;
        int len = s.length();
        boolean insert;
        StringBuilder sb = new StringBuilder("");       //存放Z变换之后的字符
        //以第一列为基础进行遍历
        for(int x=0; x<numRows; x++) {
            p = x;              //P代表当前字符在整个字符串中的位置
            insert = true;      //列首的字符的下一个字符总是插入型字符
            while(p < len) {
                sb.append(s.charAt(p));
                if (x == 0 || x == numRows-1) {     //但是第一行和最后一行除外
                    p += numRows*2-2;
                    insert = p > len ? true : false;
                    continue;
                }
                //如果不是第一行和最后一行的字符
                //分为插入型和正常型分别处理
                if (insert==false) {
                    p += 2*x;
                    insert = true;
                } else {
                    p += numRows*2-x*2-2;
                    insert = false;
                }
            }
        }
        return sb.toString();
    }
}
```
