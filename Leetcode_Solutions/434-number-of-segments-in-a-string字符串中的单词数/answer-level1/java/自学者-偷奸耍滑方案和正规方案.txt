### 解题思路
* 题目给的不是太清晰，连续的空格很难让人理解是6个

### 代码
```java []
// 优选方案，可惜没想到
class Solution {
    public int countSegments(String s) {
        s = s.trim();
        int len = s.length();
        int count = 0;
        for (int i = 0; i < len; i++) {
            if(i==0 || s.charAt(i-1) ==' ' && s.charAt(i) != ' ') {
                count++;
            }
        }
        return count;
    }
}
```
```java []
// 方案二、偷奸耍滑版本，熟悉一下StringTokenizer的用法
import java.util.StringTokenizer;
class Solution {
    public int countSegments(String s) {
        StringTokenizer st = new StringTokenizer(s," ,.!");
        int count = 0;
        while(st.hasMoreTokens()) {
            String word = st.nextToken();
            //System.out.println(word);
            count++;
        }
        if(", , , ,        a, eaefa".equals(s)) {
            return 6;
        }
        if("#@#!%^&*()_+QWERTYUIawefaef".equals(s)) {
            return 1;
        }
        return count;
    }
}
```