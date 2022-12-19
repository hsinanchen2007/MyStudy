
**解题思路：题目是对字符串的相关操作，我们第一判断将字符串转换成数组来操作。我一共共有两种解题思路**
 1. **遍历字符串按位判断情况：2ms**
 2. **运用正则表达式匹配字符串：12ms（推荐）**
 至于为什么推荐使用正则表达式来和java正则表达式相关语法可以参考我的博客：[JAVA正则表达式](https://blog.csdn.net/weixin_44392716/article/details/104083752)
### 1.遍历字符串按位判断情况：时间复杂度O(N)
 3. **我们拿到一个字符串，根据题中要求“该函数会根据需要丢弃无用的开头空格字符”，我们首先将其字符串前方的空格去掉。但是这里我们需要判断，如果输入的是一个空字符串我们需要return 0。**
 4. **当我们将字符串前方空格去掉后我们得到的字符串分为三种情况，以非数字和正负号开头（return 0；）；以正负号开头；以数字开头。**
 5. **因为以数字和正负号开头直接返回0，所以我们只需要考虑后面两种情况（以正负号开头；以数字开头）即可。当字符串以正负号开头的时候，如果正负号后面为数字我们就按位进行计算，但是如果正负号后面接着的还是正负号则为不合法字符(+-99)，需要返回0；而以数字开头的直接按位进行计算即可，直到遇到非数字字符为止。**
 6. == 如何按位计算==：**将字符一位一位的取出；例如：132先取出1，将1赋值给返回值，再取出3，将3加上返回值乘以10，再取出2，将2加上返回值乘以10。代码如下：**```java re = re * 10 + t - 48; ```**其中re为最后返回值，t为取出的字符，t-48是为了将字符型转换为整形。**
 7. **最后，每次取出字符串是要判断加上这个字符串返回值会不会溢出**
 代码如下：
```java
class Solution {
    public int myAtoi(String str) {
        //re返回值；negative负数；positive正数；isCal是否进行计算
        int re = 0,negative = 0,positive = 0,isCal = 0;
        //将字符串转换成字符数组用for-each进行遍历
        for(char t : str.toCharArray()){
            /*
             *排除前方的空格同时判断是否以除数字或者正负号以外的开头
             *如果是直接返回0
             */
            if(isCal == 0){
                if((t <= '9' && t >= '0') || t == ' ' || t == '-' || t == '+'){
                    ;
                }else{
                    return 0;
                }
            }
            //如果当前为0-9和正负号可计算，否则判断是否存在负号并进行return
            if((t <= '9' && t >= '0') || t == ' ' || t == '-' || t == '+'){
                if(t == '-'){
                    //如果前方存在正号即为"+-"则不合法返回0
                    if(positive == 1 ){
                        return 0;
                    }
                    //如果此负号前进行过计算则判断之前是否存在负号并进行return
                    if(isCal ==1){
                        if(negative == 1){
                            re = -re;
                        }
                        return re;
                    }
                    //如果是第一次遇到负号，将negative置1，同时把isCal置1代表计算过
                    negative=1;
                    isCal=1;
                }else if(t == '+'){
                    //同负号
                    if(negative == 1 ){
                        if(re !=0){
                            re = -re;
                            return re;
                        }else {
                            return 0;
                        }
                    }
                    if(isCal ==1){
                        if(negative == 1){
                            re = -re;
                        }
                        return re;
                    }
                    positive=1;
                    isCal=1;
                }else if (t == ' '){
                    //如果前方计算过又遇到空格则检查是否有负号并return
                    if(isCal != 0){
                        if(negative == 1){
                            re = -re;
                        }
                        return re;
                    }else if(isCal == 1){
                        return 0;
                    }
                }else {
                    if (negative == 1) {
                        int bbq = -re;
                        if (bbq < Integer.MIN_VALUE / 10 || (bbq == Integer.MIN_VALUE / 10 && t - 48 > 8)) {
                            return Integer.MIN_VALUE;
                        }
                    } else {
                        if (re > Integer.MAX_VALUE / 10 || (re == Integer.MAX_VALUE / 10 && t - 48 > 7)) {
                            return Integer.MAX_VALUE;
                        }
                    }
                    re = re * 10 + t - 48;
                    isCal = 1;
                }
            }else if (isCal != 0){
                if(negative == 1){
                    re = -re;
                }
                return re;
            }
        }
        if(negative == 1){
            re = -re;
        }
        return re;
    }
}
```
### 2.运用正则表达式匹配字符串：时间复杂度取决于正则表达式的匹配方式。
 1. **运用正则表达式前同样需要去除空格**
 2. **运用正则表达式匹配字符串，java正则表达式具体语法可以参考我的博客：**[JAVA正则表达式](https://blog.csdn.net/weixin_44392716/article/details/104083752)
 3. **运用正则表达式后将字符串转为整数即可，这一步可以自己写也可以调用系统方法，调用回慢3ms，调用系统方法的代码为最后一份。**

```java
//正则需要的包
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Solution {
    public int myAtoi(String str) {
        //去除字符串前面的空格
        for (int i = 0; i <str.length() ; i++) {
            if(str.charAt(i)!=' '){
                //保证字符串前方没有空格
                str=str.substring(i,str.length());
                break;
            }
        }
        //用正则表达式进行判断
        Pattern pattern = Pattern.compile("^[\\+\\-]?\\d+");
        Matcher matcher = pattern.matcher(str);
        //如果存在字符串则进行转换
        int re=0,t=0;
        if(matcher.find()){
            //进行截取字符串(此时字符串带正负号）
            str=str.substring(matcher.start(),matcher.end());
            //如果是负数
            if(str.charAt(0) == '-'){
                for (int i = 1; i < str.length() ; i++) {
                    t = str.charAt(i);
                    int bbq = -re;
                    if (bbq < Integer.MIN_VALUE / 10 || (bbq == Integer.MIN_VALUE / 10 && t - 48 > 8)) {
                        return Integer.MIN_VALUE;
                    }
                    re = re*10 + t - 48;
                }
                return -re;
            }else if (str.charAt(0) == '+'){
                for (int i = 1; i < str.length() ; i++) {
                    t = str.charAt(i);
                    if (re > Integer.MAX_VALUE / 10 || (re == Integer.MAX_VALUE / 10 && t - 48 > 7)) {
                        return Integer.MAX_VALUE;
                    }
                    re = re*10 + t - 48;
                }
                return re;
            } else{
                for (int i = 0; i < str.length() ; i++) {
                    t = str.charAt(i);
                    if (re > Integer.MAX_VALUE / 10 || (re == Integer.MAX_VALUE / 10 && t - 48 > 7)) {
                        return Integer.MAX_VALUE;
                    }
                    re = re*10 + t - 48;
                }
                return re;
            }
        }else{
            return 0;
        }
    }
}
```
调用系统方法的代码
```java
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Solution {
    public int myAtoi(String str) {
        //去除字符串前面的空格
        for (int i = 0; i <str.length() ; i++) {
            if(str.charAt(i)!=' '){
                //保证字符串前方没有空格
                str=str.substring(i,str.length());
                break;
            }
        }
        //用正则表达式进行判断
        Pattern pattern = Pattern.compile("^[\\+\\-]?\\d+");
        Matcher matcher = pattern.matcher(str);
        //如果存在字符串则进行转换
        int re=0,t=0;
        //判断是否能匹配
        if (matcher.find()){
            //字符串转整数，溢出
            try {
                re = Integer.parseInt(str.substring(matcher.start(), matcher.end()));
            } catch (Exception e){
                //判断'-'
                re = str.charAt(0) == '-' ? Integer.MIN_VALUE: Integer.MAX_VALUE;
            }
        }
        return re;
    }
}
```
# 最后附上我的leetcode刷题目录[leetcode刷题目录](https://blog.csdn.net/weixin_44392716/article/details/103225729)