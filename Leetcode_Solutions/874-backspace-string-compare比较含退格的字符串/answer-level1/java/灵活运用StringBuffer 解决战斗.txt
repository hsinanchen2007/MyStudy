### 解题思路
思路：运用StringBuffer处理字符拼接问题
    1. StringBuffer创建空字符串
    2.  if 当字符 (c != '#') 继续拼接
    3. else 即当字符 (c == '#') 先判断 字符串(不为空)长度 >0 即删除一个字符
    4. 最终字符串转成String

### 代码

```java
class Solution {
    public boolean backspaceCompare(String S, String T) {
        return build(S).equals(build(T));
    }
    public String build(String s){
        StringBuffer buffer = new StringBuffer();
        for (char c :s.toCharArray()) {
            if (c != '#') {
                buffer.append(c);
            } else {
                if (buffer.length() > 0) {
                    buffer.deleteCharAt(buffer.length()-1);
                }
            }
        }

        return String.valueOf(buffer);
    }
}
```