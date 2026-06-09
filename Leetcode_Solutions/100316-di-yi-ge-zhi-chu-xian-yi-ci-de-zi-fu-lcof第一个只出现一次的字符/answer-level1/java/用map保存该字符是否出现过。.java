### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
        char[] chars=s.toCharArray();
        Map<Character, Boolean> existMap = new HashMap<>();
        char[] sc = s.toCharArray();
        for(char c : sc)
            existMap.put(c, !existMap.containsKey(c));
        for(char c : sc)
            if(existMap.get(c)) return c;
        return ' ';
    }
}
```