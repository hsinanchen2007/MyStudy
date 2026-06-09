### 解题思路
 暴力解法

### 代码

```java
class Solution {
    public boolean isMatch(String s, String p) {
         char []s1=s.toCharArray();
        char []s2=p.toCharArray();
        return match(s1,s2);
    }
   public static boolean match(char[] str, char[] pattern) {
        if (str == null || pattern == null)
            return false;
        return matchCore(str, 0, pattern, 0);
    }

    private static boolean matchCore(char[] str, int indexOfStr, char[] pattern, int indexOfPattern) {
        if (indexOfStr == str.length && pattern.length == indexOfPattern) {
            return true;
        }
        if (indexOfStr < str.length && indexOfPattern == pattern.length) { //当表达式以及匹配完，而输入字符串还没有匹配完  则匹配错误
            return false;
        }
        if (indexOfPattern + 1 < pattern.length && pattern[indexOfPattern + 1] == '*') {//判断*的情况
            if ((indexOfStr < str.length && pattern[indexOfPattern] == '.') ||
                    (indexOfStr < str.length && pattern[indexOfPattern] == str[indexOfStr]))
            {
                //这里有三种情况
                return matchCore(str, indexOfStr, pattern, indexOfPattern + 2)//已经匹配到重复的最后一个
                        || matchCore(str, indexOfStr + 1, pattern, indexOfPattern)//重复匹配中
                        || matchCore(str,indexOfStr+1,pattern,indexOfPattern+2);//匹配到最后一个重复的字符
            }else {
                return matchCore(str,indexOfStr,pattern,indexOfPattern+2);

            }
        }
        if(indexOfStr<str.length&&str[indexOfStr]==pattern[indexOfPattern]||(indexOfStr < str.length && pattern[indexOfPattern] == '.')){
            return  matchCore(str,indexOfStr+1,pattern,indexOfPattern+1);
        }
        return false;
    }
}
```