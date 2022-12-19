### 解题思路
开始还以为是动规相关的题，想想简单题也不至于，然后没什么说的，找出最短的字符串，然后依次判断每个位置是不是都相同，不相同就返回

### 代码

```java
import java.util.Arrays;
import java.util.Stack;
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length==0)return "";
        int min = Arrays.stream(strs).mapToInt(String::length).min().getAsInt();
        StringBuilder builder = new StringBuilder();
        int index = -1;
        while (++index < min) {
            boolean allSame = true;
            for (int i = 1; i < strs.length; i++) {
                if (strs[i].charAt(index) != strs[i - 1].charAt(index))
                    allSame = false;
            }
            if (allSame) builder.append(strs[0].charAt(index));
            else break;
        }
        return builder.toString();
    }
}
```