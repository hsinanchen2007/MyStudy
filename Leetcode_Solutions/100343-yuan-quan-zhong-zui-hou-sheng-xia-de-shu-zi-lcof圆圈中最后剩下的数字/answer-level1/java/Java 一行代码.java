### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        //f(N,M)=(f(N−1,M)+M)%N
        return n == 1 ? 0 : (lastRemaining(n - 1, m) + m) % n;
    }
}
```