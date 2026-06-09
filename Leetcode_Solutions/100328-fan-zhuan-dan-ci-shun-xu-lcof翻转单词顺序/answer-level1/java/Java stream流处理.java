```java
import java.util.StringJoiner;
class Solution {
    public String reverseWords(String s) {
        if(s == null)return s;
        //trim去除两端空白字符
        //filter使用正则表达式过滤掉空白字符串
        //str.matches("\\s*")表示匹配任意长度的空白字符
        List<String> tmp = Arrays.stream(s.trim().split(" ")).filter(str->!str.matches("\\s*")).collect(Collectors.toList());
        //反转字符串数组的顺序
        Collections.reverse(tmp);
        //StringJoiner负责把字符串拼接
        StringJoiner sj = new StringJoiner(" ");
        for (String s1 : tmp) {
            sj.add(s1);
        }
        return sj.toString();
    }
}
```