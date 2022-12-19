### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numJewelsInStones(String J, String S) {
        return S.replaceAll("[^"+J+"]", "").length();
    }
}
```