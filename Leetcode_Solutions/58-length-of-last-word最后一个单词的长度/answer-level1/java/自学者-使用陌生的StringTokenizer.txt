### 解题思路
* StringTokenizer会将输入字符串按照空格进行搜索词拆分
* 直接返回最后一个分词的长度即可
* 默认给个空字符串，如果没有分词，直接返回0

### 代码

```java
import java.util.StringTokenizer;
class Solution {
    public int lengthOfLastWord(String s) {
        StringTokenizer st = new StringTokenizer(s);
        String last = "";
        while( st.hasMoreTokens()) {
            last = st.nextToken();
        }
        return last.length();
    }
}
```