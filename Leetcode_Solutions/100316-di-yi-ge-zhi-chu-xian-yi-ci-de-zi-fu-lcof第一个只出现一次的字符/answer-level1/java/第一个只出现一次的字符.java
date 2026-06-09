### 解题思路
这个思路比较常见
### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
        char [] chars=new char[26];
        char [] a=s.toCharArray();
        for(char c:a)
        {
            chars[c-'a']++;
        }
        for(char c:a)
        {
            if(chars[c-'a']==1)
                return c;
        }
        return ' ';
    }
}
```