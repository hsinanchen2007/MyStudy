### 解题思路
博君一笑，不要当真，不过这个在面试的时候估计会被禁

### 代码

```java
class Solution {
    public String replaceSpaces(String S, int length) {
        S = S.substring(0,length);
        String result = S.replaceAll("\\s","%20");
        return result;
    }
}
```