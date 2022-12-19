### 解题思路
我采用记录空格来判断单词数目。
记录空格有地方需要处理。一个是前导和后导空格；还有一个是多个空格的情况。
采用去除空格函数和正则表达式解决了。

### 代码

```java
class Solution {
    public int countSegments(String s) {
        s = s.trim();
        if(s.length() == 0)
            return 0;

        s = s.replaceAll("\\s{1,}", " ");
        int ans = 0;
        char[] chars = s.toCharArray();

        for(int i = 0; i < chars.length; i++){

            if(chars[i] == ' ' )
                ans++;
        }
        
        return ans+1;
    }
}
```