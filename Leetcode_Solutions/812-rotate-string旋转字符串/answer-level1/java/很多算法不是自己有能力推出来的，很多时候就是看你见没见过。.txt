### 解题思路
很多算法不是自己有能力推出来的，很多时候就是看你见没见过，所以要多做题。
题海战术无法助你达到世界级水准，但是超过绝大多数人应该够用了。

### 代码

```java
class Solution {
    public boolean rotateString(String A, String B) {
        return A.length() == B.length() && (A + A).contains(B);
    }
}
```