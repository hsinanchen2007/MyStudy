### 解题思路
感觉没有用到贪心和动态规划的技巧。。。

### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        int lens = s.length();
        int lent = t.length();
        int i, j;
        
        if(lens > lent)
            return false;
        if(lens == 0)
            return true;

        for(i = 0, j = 0; i < lent && j < lens; i++){
            if(t.charAt(i) == s.charAt(j))
                j++;
        }
        if(j == lens)
            return true;
        return false;
    }
}
```