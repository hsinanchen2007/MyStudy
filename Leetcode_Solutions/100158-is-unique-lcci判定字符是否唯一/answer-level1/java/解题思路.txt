### 解题思路
把字符串分割成一个个字符放入具有唯一性的set集合中，如果set的尺寸与字符串长度一致，则字符串的字符都不相同

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        Set<Character> set = new HashSet<>();
        for (char c : astr.toCharArray()) {
            set.add(c);
        }
        return set.size() == astr.length();
    }
}
```