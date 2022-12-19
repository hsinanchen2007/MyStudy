### 解题思路
理解题意后可以发现，同构字符串等价于，**来自两个字符串中的一对字符，若它们下标相同，则它们在各自字符串中第一次出现的位置也相同**，满足这个要求的两个字符串就是同构字符串。

### 代码

```java
class Solution {
    public boolean isIsomorphic(String s, String t) {
        int len = s.length();
        for(int i=0; i<len; i++)
        {
            char a = s.charAt(i);
            char b = t.charAt(i);
            if(s.indexOf(a) != t.indexOf(b))
                return false;
        }
        return true;
    }
}
```