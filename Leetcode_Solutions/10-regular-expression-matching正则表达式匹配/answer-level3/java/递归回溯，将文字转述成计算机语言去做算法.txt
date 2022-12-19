
我们先将text代表原串，pattern代表匹配规则串

其中题目中关键信息

**'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素**

将这两句话转成算法就是解题思路，首先逐个比对然后满足进位，采用递归

下面我们再看‘.’的匹配规则，那么在判定时候做任意字符串匹配

然后我们再看‘*’匹配规则，包含两种情况都可以，所以在匹配时候需要有或的判断。
第一种是匹配代表零个情况，则需要看截取pattern两位后的字符串与text的匹配情况；
第二种是代表任意个，这时候匹配成功就应该用text向后截取继续匹配pattern。

根据上面的分析，参照代码中的注释。其实写代码，就是要抽象理解转换成计算机的语言和算法。


```Java
public boolean isMatch(String text, String pattern) {
        //递归回溯结束点
        if (pattern.isEmpty()) {
            return text.isEmpty();
        }
        boolean first_match = (!text.isEmpty() &&
                (pattern.charAt(0) == text.charAt(0) || pattern.charAt(0) == '.'));

        //如果pattern长度大于2并且第二位是*，这一步isMatch3(text, pattern.substring(2)可以判定用到*匹配零个前字符isMatch3(text, pattern.substring(2)
        if (pattern.length() >= 2 && pattern.charAt(1) == '*') {
            //这个匹配判定用到*匹配零个前字符
            return (isMatch3(text, pattern.substring(2)) ||
                    //这个匹配判定*代表n个字符
                    (first_match && isMatch3(text.substring(1), pattern)));
        } else {
            //判定第二位不是*的情况都移位判定，每回递归只判断第一位，直到空
            return first_match && isMatch3(text.substring(1), pattern.substring(1));
        }
    }
```
