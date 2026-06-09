### 解题思路
使用java字符串的indexOf()函数，顺序遍历字符串，如果两个字符串每个字符第一次出现的下标都相等，则两字符串一定同构。

### 代码

```java
class Solution {
    public boolean isIsomorphic(String s, String t) {
        for(int i = 0; i < s.length(); i ++)
            if(s.indexOf(s.charAt(i)) != t.indexOf(t.charAt(i)))
                return false;
        return true;        
    }
}
```
### 问题
时间复杂度比O(n)大。