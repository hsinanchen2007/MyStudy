### 解题思路
1，如何判断是否满足'10#' - '26#'的特殊转换
1）i+2是否在s的有效长度内
2）i+2是否是'#'
3）i是‘1’，则一定满足特殊转换条件；i是'2'，需判断i+1是否是‘0’到‘6’之间

伪代码如下：
```
if s是null
    返回null
for 遍历s
    if 当前字符是'0'
        保存'0'
    else if 满足'10#' - '26#'
        保存转换后的字符
        i往多后移2位（加上for循环的共3位）
    else
        字符（'a' - 'i'）分别用（'1' - '9'）表示

```

2，实际编码时要注意的点
1）int转char需要强制转换，反之不用强转
2）String转char：String.charAt
3）特殊转换时，下标一共会后移3位
4）字符串拼接记得用StringBuffer
5）不需要查ascII表，只需要用字符相减就可以得到转换的偏移量

### 代码

```java
class Solution {
    public String freqAlphabets(String s) {
        if(s==null)
            return null;

        StringBuffer result = new StringBuffer();
        char tmpChar = ' ';
        int highTmp;
        
        for(int i=0;i<s.length();i++) {
            if(s.charAt(i) == '0') {
                tmpChar = '0';
            }else if(i+2<s.length() && s.charAt(i+2)=='#') {
                if(s.charAt(i)=='1' || s.charAt(i)=='2') {
                    //int -> char需要强制转换， 反之不用
                    highTmp = '2' - s.charAt(i);
                    if(highTmp==0) {
                        //高位是2, '20#'是't'
                        if(s.charAt(i+1)>='0' && s.charAt(i+1)<='6') {
                            tmpChar = (char)('t' + s.charAt(i+1) - '0');
                            i = i+2;
                        }else
                            //#前面的数大于26了
                            tmpChar = (char)(s.charAt(i) + 'a' - '1');
                    }else {
                        //高位是1
                        tmpChar = (char)('j' + s.charAt(i+1) - '0');
                        //i多加2
                        i += 2;
                    }                    
                }
            }else {
                //System.out.print("before tmpChar:" + s.charAt(i) + '\n');
                tmpChar = (char)(s.charAt(i) + 'a' - '1');
                //System.out.print("after tmpChar:" + tmpChar + '\n');
            }

            result.append(tmpChar);     
        }

        return result.toString();
    }
}
```