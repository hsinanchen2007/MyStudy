思路：一般解法的思路是取子串，测试是否满足题目条件。正则的思路就是匹配字符串是否满足由前面的子串至少重复一次。
<br/><br/>
一般解法详细思路和代码：

1. 利用StringAPI，如果全是重复的子字符串，那么使用split函数拆分后的数组长度将会是0
2. 找字符串长度的因子，挨个去拆分出子串，去测试满足split函数拆分的数组长度是否为0
3. split函数使用的规则是正则匹配，效率略低
```
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        if (s == null) {
            return false;
        }
        
        // 长度为1，不能拆分出子串，所以直接返回false
        if (s.length() == 1) {
            return false;
        }
        
        // 长度大于1，可以拆分出子串，判断字符串中是否所有字符都相同，如"aaaaaa","zzz"，一定满足按子串长度为1的拆分，所以直接返回true
        if (s.split(String.valueOf(s.charAt(0))).length == 0) {
            return true;
        }
        
        // 找长度最长的因子，拆分出子串
        for (int i = s.length() - 1;i >= 2;i--) {
            if (s.length() % i == 0) {
                String pattern = s.substring(0,i);
                String arr[] = s.split(pattern);
                if (arr.length == 0) {
                    return true;
                }
            }
        }
        
        return false;
    }
}
```
<br/><br/>
正则表达式解法代码：
```
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        return s.matches("(\\w+)\\1+");
    }
}
```
<br/><br/>
效率比较：上面的是正则表达式的解法时间消耗，下面的是一般取子串的解法时间消耗
![image.png](https://pic.leetcode-cn.com/ff65198d33aa03e18727baa5500e4f754c243c3f580761e9c508202fdefbd57f-image.png)