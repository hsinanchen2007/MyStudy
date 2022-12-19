# 正则表达式能做什么？
正则表达式可以用来搜索、编辑或处理文本。
![neiko.jpg](https://pic.leetcode-cn.com/6a8c981a79a3f1f31a61d1550ec857645453041eeeb85f93f95fac655665fcf1-neiko.jpg)

「都懂它可以处理文本，可到底是怎么回事？」
# 正则表达式的定义
百度百科：正则表达式是对字符串操作的一种逻辑公式，就是用事先定义好的一些特定字符、及这些特定字符的组合，组成一个“规则字符串”，这个“规则字符串”用来表达对字符串的一种过滤逻辑。

所以正则表达式它「首先不同的语言之间的正则表达式有细微的区别」：
^[a-z0-9_-]{3,15}$就是一个标准的正则表达式，它用来检测用户注册登录名时，用户名只可以包含字符、数字、下划线和连接字符并且用户名的长度必须在3-15个字符的范围内。

[...]    方括号内为匹配的规则，a-z 为匹配从 a 到 z 的字符，0-9 为匹配 0 到 9 的数字。
{m,n} 正则表达式里的花括号表示：匹配前面的内容至少m次，至多n次，上图中则表示匹配用户名至少3次至多15次，限制了用户名的长度。
所以上述的正则表达式在实际应用的时候是什么样子的呢？

Java版本：
```
public static void main(String args[]) {
        String UserName = "nicolas";

        String pattern = "^[a-z0-9_-]{3,15}$";
        //String pattern = "\\w{3,15}";也可以
　　　　 boolean isMatch = Pattern.matches(pattern, UserName); System.out.println("用户名是否合规? " + isMatch); }
```
输出：`用户名是否合规? true`
#  正则表达式的实际案例
首先添加一个Java正则的语法：

\num : 匹配 num，此处的 num 是一个正整数。到捕获匹配的反向引用。例如，"(.)\1"匹配两个连续的相同字符。

\d : 数字字符匹配。等效于 [0-9]。

*   : 零次或多次匹配前面的字符或子表达式。例如，zo* 匹配"z"和"zoo"。* 等效于 {0,}。

那么不难看懂： 「    (\d)\1*    」的含义为：匹配两个连续0次以上的相同数字

前文中用到了 ：`Pattern.matches(pattern, UserName);`
Java来做正则表达式的时候 有两个重要的类：Matcher 和 Pattern，下面首先讲一下Matcher 和 Pattern
# Pattern

1. Pattern.matcher(CharSequence input)
对指定输入的字符串创建一个Matcher对象。Matcher对象一般通过这个方法生成。CharSequence是个interface，String类实现了CharSequence接口，因此可以传入String类型的值。
例如：
```
Pattern pattern = Pattern.compile("\\?{2}");
Matcher matcher = pattern.matcher("??");
//matcher的matches方法是对字符串整合匹配。只有整个字符串符合正则表达式才会返回true
boolean matches = matcher.matches();// true
```

2. Pattern compile(String regex)
由于Pattern的构造函数是私有的,不可以直接创建,所以通过静态方法compile(String regex)方法来创建,将给定的正则表达式编译并赋予给Pattern类。
例如：`Pattern pattern = Pattern.compile("\\?{2}");`
# Matcher
1. boolean matches()
     最常用方法:尝试对整个目标字符展开匹配检测,也就是只有整个目标字符串完全匹配时才返回真值.
2. boolean lookingAt()
     对前面的字符串进行匹配,只有匹配到的字符串在最前面才会返回true
3. boolean find()
     对字符串进行匹配,匹配到的字符串可以在任何位置
        String group()
        返回匹配到的子字符串
# 话不多说，我们先看解题代码：

```
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class NO38 {
    public String countAndSay(int n) {
        StringBuilder sb = new StringBuilder("1");
        while(--n>0){
            Matcher matcher = Pattern.compile("(\\d)\\1*").matcher(sb.toString());
            sb.setLength(0);//将StringBuffer清空
            while(matcher.find()){  //当查找到了相应到字符串
                String num = matcher.group(0);
                sb.append(num.length()+num.substring(0,1));
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        NO38 solution = new NO38();
        String s = solution.countAndSay(5);
        System.out.println(s);
    }
}
```

第8行： 将compile和matcher连用了，其实是可以分开写的，写成：
```
 Pattern p = Pattern.compile("(\\d)\\1*");
 Matcher m = p.matcher(sb.toString);
```
第9行： 每次循环开始前要把StringBuffer清空，因为每次都要将上一次的结果清空，比如n=1时，sb=1,那么n=2时需要清空前面的sb值再令sb=11，这个清空sb内容的操作就由第9行代码来完成。

第10-13行： 前面说到来  find() 是部分匹配，所以写在了while循环内，这样可以在每一次部分匹配成功时，进行一次操作。“matcher.group(0)”是将匹配到的字符串返回，然后获取这个字符串的长度，再进行一次拼接，完成操作

# 结束语：
首先我很菜，写错的地方麻烦大佬纠正我去修改一下。
正则表达式的简单操作就是这样，后面一些进阶的内容待我以后慢慢完善。




「this page is for my "xxx"」