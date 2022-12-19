### 解题思路
此处撰写解题思路
记住:1.s.to***Char***Array();
2.***map.***getOrDefault()
执行用时 :
32 ms
, 在所有 Java 提交中击败了
51.88%
的用户
内存消耗 :
39.9 MB
, 在所有 Java 提交中击败了
100.00%
的用户
### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        char[] cs = s.toCharArray();
        for (char c : cs){
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        for (char c : cs){
            if (map.get(c) == 1) return c;
        }
        return ' ';
    }
}
```