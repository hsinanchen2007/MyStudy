### 解题思路
有点强行一句

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        return new StringBuilder(
                Arrays.stream(s.split(" "))
        		    .map(i -> i.trim())
        		    .filter(i -> i.length()>0)
        		    .map(i -> i.length() > 1 ? new StringBuilder(i).reverse().toString() : i)
        		    .collect(Collectors.joining(" "))).reverse().toString();
    }
}
```