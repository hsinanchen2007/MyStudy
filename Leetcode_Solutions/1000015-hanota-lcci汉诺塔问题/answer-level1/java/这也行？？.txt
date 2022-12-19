### 解题思路
![image.png](https://pic.leetcode-cn.com/7f82bdf2ac56d17fc83a011ddb24cb0c128e93116bcdbacf582418bb0d3de655-image.png)


### 代码

```java
class Solution {
    public void hanota(List<Integer> A, List<Integer> B, List<Integer> C) {
        C.addAll(A);
        A.clear();
    }
}
```