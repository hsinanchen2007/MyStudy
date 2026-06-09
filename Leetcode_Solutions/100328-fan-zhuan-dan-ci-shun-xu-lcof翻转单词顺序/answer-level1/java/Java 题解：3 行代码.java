Java 3 行偷懒方法：
```java
class Solution {
    public String reverseWords(String s) {
        List<String> res = Arrays.asList(s.trim().split(" "));
        Collections.reverse(res);
        return res.stream().filter(str -> !str.isEmpty()).collect(Collectors.joining(" "));
    }
}
```
