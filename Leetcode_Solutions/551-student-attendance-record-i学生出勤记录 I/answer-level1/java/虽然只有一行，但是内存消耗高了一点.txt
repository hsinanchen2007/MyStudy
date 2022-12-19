### 解题思路
contains()查找三个连续的L比较简单，统计A的数量麻烦了一点
### 代码

```java
class Solution {
    public boolean checkRecord(String s) {
    	return !s.contains("LLL") && (s.indexOf("A") == -1 || (s.indexOf("A", s.indexOf("A") + 1) == -1));

    }
}
```