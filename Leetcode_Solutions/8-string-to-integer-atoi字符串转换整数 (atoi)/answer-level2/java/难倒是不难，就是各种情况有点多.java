### 解题思路
这道题真的是，思路很容易就有了，就是这情况太多了，一下子很难思虑的如此周详。

这道题关键的就是要保证连续数字，并且，开头的正负号只能有一个。

我是先转换成long类型的再转int，但是如果数字过大，long也不行，所以，可以判断一下长度是否超过了10位。如果超过10位就可以直接返回Integer.MAX_VALUE。

其中有个小关键的方法就是将字符类型的'3'转换成数字类型的3。通过'3'-'0'就可以实现。

还有要注意char数组的初始值是'\u0000'，表示空字符，它打印出来虽然是空格，但是不和' '等价，也不和null等价。
Character.MIN_VALUE == '\u0000' 为true，下面代码中的判断可以换成Character.MIN_VALUE。
### 代码

```java
class Solution {
    public int myAtoi(String str) {
        //将数字放到字符数组中
        char[] ch = new char[str.length()];
        //正负号
        String prefix = "";
        //ch索引
        int in = 0;
        //如果出现0之后再出现空格，应该直接结束
        //正负号也只能有一个
        boolean flag = true;
        for (char c : str.toCharArray()){
            if (flag && c == ' ' && ch[0] == '\u0000') continue;
            else if (flag && c == '+' && ch[0] == '\u0000' && prefix.equals("")){
                prefix = "+";
                flag = false;
            }
            else if (flag && c == '-' && ch[0] == '\u0000' && prefix.equals("")){
                prefix = "-";
                flag = false;
            }
            else if (c == '0' && ch[0] == '\u0000') flag = false;
            else if (c <= '9' && c >= '0') ch[in++] = c;
            else break;
        }
        //表示位数（个位、十位。。。）
        int n = 0;
        //最后的结果
        long res = 0;
        //单个数
        int m = 0;
        for (int i = ch.length-1; i >= 0; i--){
            if (ch[i] != '\u0000'){
                m = ch[i] - '0';
                res += m * pow(n);
                if (i > 9 || res > Integer.MAX_VALUE){
                    if (prefix.equals("+")) return +Integer.MAX_VALUE;
                    if (prefix.equals("-")) return Integer.MIN_VALUE;
                    return Integer.MAX_VALUE;
                }
                n++;
            }
        }
        if (prefix.equals("+")) return +(int)res;
        if (prefix.equals("-")) return -(int)res;
        return (int)res;
    }
    //10的n次方
    private long pow(int n){
        long m = 1L;
        for (int i = 0; i < n; i++){
            m *= 10;
        }
        return m;
    }
}
```