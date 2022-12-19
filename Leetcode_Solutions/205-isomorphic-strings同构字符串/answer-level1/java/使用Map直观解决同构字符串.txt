### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isIsomorphic(String s, String t) {
        int length = s.length();
        Map<Character, Character> map = new HashMap<>();
        for (int i = 0; i < length; i++) {
            if (map.containsKey(s.charAt(i))) {
                // 所有出现的字符都必须用另一个字符替换
                if (map.get(s.charAt(i)) != t.charAt(i)) {
                    return false;
                }
            } else {
                // 两个字符不能映射到同一个字符上
                if (map.containsValue(t.charAt(i))) {
                    return false;
                }
                map.put(s.charAt(i), t.charAt(i));
            }
        }
        return true;
    }
}
```