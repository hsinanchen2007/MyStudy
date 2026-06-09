### 解题思路

字符只出现一次，也就是第一次出现的索引和第二次出现的索引相同。因此可以通过一次遍历判断。但 indexOf 的时间复杂度是 O(m x n)，再加上遍历，整个算法的时间复杂度是 O(m x n^2)。

### 代码

```java
class Solution {
    public int firstUniqChar(String s) {
        for(int i = 0; i < s.length(); i++) {
            if(s.lastIndexOf(s.charAt(i)) == s.indexOf(s.charAt(i))) return i;
        }
        
        return -1;
    }
}
```