### 解题思路
首先，两个字符串若为字母异位词，则它们长度必相等，否则返回false
其次，将两个字符串转化为字符数组
然后，将字符数组排序后进行比较

### 代码

```java
class Solution {
    public boolean isAnagram(String s, String t) {
    if(s.length()!=t.length()) { 
       return false;
    }
    char[] str1=s.toCharArray();
    char[] str2=t.toCharArray();
    Arrays.sort(str1);
    Arrays.sort(str2);
    return Arrays.equals(str1,str2);
    }
}
```