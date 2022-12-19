### 解题思路
此题主要考察两个知识点

1. 表层的知识点是简单的字符串替换

2. 隐藏的知识点是考察了在字符串替换中可能需要用到的正则表达式，由于正则表达中 "." 是一个特殊字符，所以在替换IP地址中的 "." 时需要转义。除了 "."，正则表达式中的特殊字符还有 ".$|()[{^?*+\\" 等等

> Java版本示例代码解析题库：https://github.com/llyer/leetcode

> 参考链接：https://www.cnblogs.com/chevin/p/9241468.html



### 代码

```java
class Solution {
    public String defangIPaddr(String address) {
        String[] splits = address.split("\\.");
        StringBuffer stringBuffer = new StringBuffer();
        for (String split : splits) {
            stringBuffer.append(split + "[.]");
        }
        return stringBuffer.toString().substring(0, stringBuffer.length() - 3);
    }
}
```