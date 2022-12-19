### 解题思路
给一个自己写的贪心算法的思路，每移动一个字符都找到最大长度

### 代码

```java
class Solution {
   	public int lengthOfLongestSubstring(String s) { 
        if (s == null || s.length() == 0) {
            return 0;
        }
        int len = 1; //前不重复子串长度。
        int max = 1; //到前一个字符为止最大子串长度。
        for (int i = 1; i < s.length(); i++) {
            for (int j = i - len; j < i; j++) { //从不重复子串开始。
                if (s.charAt(i) == s.charAt(j)) { 
                    len = i - j - 1; //如果重复，长度变为两字符中间的长度。
                    break;
                }
            }
            len++; //添加当前字符，长度+1。
            max = Math.max(max, len); //最大长度。
        }
        return max;
    }

}
```