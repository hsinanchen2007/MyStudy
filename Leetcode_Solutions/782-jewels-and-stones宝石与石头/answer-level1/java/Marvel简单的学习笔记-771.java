### 执行用时：1ms
用boolean[]数组记录某个字母是否代表宝石，宝石为true，否则为false。遍历J字符串构造boolean[]数组，然后再遍历S字符串统计有多少个宝石。

时间复杂度：O(n)。n为两个字符串中所有字母的个数。
空间复杂度：O(1)。一共只有52个字母，故哈希表大小为常数。

### 代码

```java
class Solution {
    public int numJewelsInStones(String J, String S) {
        boolean[] hash = new boolean[52];
        int cnt = 0;
        
        char[] j = J.toCharArray();
        for(char c : j)
        {
            if(c >= 'a' && c <= 'z')    hash[c - 'a'] = true;
            if(c >= 'A' && c <= 'Z')    hash[c - 'A' + 26] = true;
        }
        char[] s = S.toCharArray();
        for(char c : s)
        {
            if(c >= 'a' && c <= 'z' && hash[c - 'a'])   
                cnt++;
            if(c >= 'A' && c <= 'Z' && hash[c - 'A' + 26])
                cnt++;
        }
        return cnt;
    }
}
```