### 解题思路
第一个indexOf获取第一个下标，
第二个indexOf判断截取的字符串还是否有这个字符，如果没有这个字符则是第一个单字符。

### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
        for (int i = 0; i < s.length(); i++) {
            int index = s.indexOf(s.charAt(i));

            if (index != -1) {
                String tmp = s.substring(index+1);
                if (tmp.indexOf(s.charAt(i)) == -1) {
                    return s.charAt(i);
                }
            }
        }
        return ' ';
    }
}
```