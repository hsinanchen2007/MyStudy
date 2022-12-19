### 解题思路
i指向子串的左边、j指向右边，子串一直保持无重复
用hash表存储字符当前最后出现的位置
j向右移的条件，当j+1的字符 在[i,j]区段没有出现  (!pos.containsKey(s.charAt(j))||pos.get(s.charAt(j))<i)
当不符合，则将i放到[i,j]出现j+1字符的右边，j++

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> pos = new HashMap<Character, Integer>();
        int i=0,j=0,res = 0;
        while (i<s.length()&&j<s.length()) {
            // 右边生长
            while (j<s.length() && (!pos.containsKey(s.charAt(j))||pos.get(s.charAt(j))<i)) {
                pos.put(s.charAt(j), j++);
            }
            // 此时j出现重复 或者 到了右端
            res = Math.max(res, j-i);
            if (j<s.length()) {
                int firstPos = pos.get(s.charAt(j));
                i = firstPos+1;
            }
        }
        return res;
    }
}
```
![image.png](https://pic.leetcode-cn.com/d9c2ffa6f9c7d6f682fae44a85ec48734c0fcd08a8216a339fb4f50e5bf5f47b-image.png)
