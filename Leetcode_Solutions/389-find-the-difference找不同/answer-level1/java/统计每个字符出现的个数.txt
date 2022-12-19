### 解题思路
统计两个字符串每个字母出现的个数
然后比较哪个字母出现次数不同

### 代码

```java
class Solution {
    public char findTheDifference(String s, String t) {
        int[] countS = new int[26];
        int[] countT = new int[26];
        // 统计s和t中每个字母个数
        for (int i = 0; i < s.length(); i++) {
            countS[s.charAt(i) - 97]++;
            countT[t.charAt(i) - 97]++;
        }
        // t 比 s 多了一个字母
        countT[t.charAt(t.length() - 1) - 97]++;
        
        // 查询出现次数不同的字母
        for (int i = 0; i < 26; i++) {
            if (countS[i] != countT[i]) {
                return (char)(i+97);
            }
        }
        

        return '1';
        
    }
}
```