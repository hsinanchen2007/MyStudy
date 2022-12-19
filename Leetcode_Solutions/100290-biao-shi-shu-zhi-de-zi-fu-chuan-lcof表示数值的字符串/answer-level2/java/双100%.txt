
### 代码

```java
class Solution {
    //index遍历进行搜索整个字符串
    private int index = 0;
    public boolean isNumber(String s) {
        //空字符串非数值
        if(s.length() == 0) return false;
        s = s.trim();
        boolean A = scanInteger(s),B = false,C = false;
        //遇到小数点
        //判断后面是不是无符号的整数
        if(index < s.length() && s.charAt(index) == '.'){
            index++;
            //判断小数点后面的数字是不是无符号整数
            //有符号不行
            B = scanUnsignedInteger(s);
        }
        //遇到指数e标记，先加1，再继续往下计算
        if(index < s.length() && (s.charAt(index) == 'e' || s.charAt(index) == 'E')){
            index++;
            C = scanInteger(s);
            //如果C不是整数，表示指数位后面不为整数，则为false
            if(C == false) return false;
        }
        //遍历到最后，并且是
        //有A的话A、B都可以，没有A的话就一定要有B，如.1 .45都是正常的数字
        return index == s.length() && (A || B);
    }
    //判别是否是整数（有符号）
    public boolean scanInteger(String s){
        if(index < s.length() && (s.charAt(index) == '+' || s.charAt(index) == '-'))
            index++;
        return scanUnsignedInteger(s);
    }
    //判别是否是无符号的整数
    public boolean scanUnsignedInteger(String s){
        int start = index;
        while(index < s.length() && s.charAt(index) >= '0' && s.charAt(index) <= '9'){
            index++;
        }
        return index > start;
    }
}
```