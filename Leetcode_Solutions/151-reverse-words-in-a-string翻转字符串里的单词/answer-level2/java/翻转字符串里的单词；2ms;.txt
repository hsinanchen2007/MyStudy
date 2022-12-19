### 解题思路
将字符串每个单词提取出来作为字符串数组，再从数组最后一个单词开始将字符串连接起来即可。

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        s = s.trim();
        StringBuffer str = new StringBuffer();
        String[] wordes = s.split(" ");
        for (int i = wordes.length - 1; i >= 0 ; i--) {
            if(!wordes[i].isEmpty()) {
                str.append(wordes[i] + " ");
            }
        }
        return str.toString().trim();
    }
}
```