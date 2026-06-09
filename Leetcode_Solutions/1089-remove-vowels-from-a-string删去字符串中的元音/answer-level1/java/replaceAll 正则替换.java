### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String removeVowels(String S) {
        return S.replaceAll("[aeiou]", "");
    }
}
```