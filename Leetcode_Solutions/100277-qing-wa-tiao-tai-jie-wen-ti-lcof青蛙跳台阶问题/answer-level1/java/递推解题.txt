### 解题思路

1. 青蛙跳台阶，假设青蛙跳N层台阶，那么可能性等于 (青蛙跳 N-1 + 青蛙跳一层) + (青蛙跳 N-2 + 青蛙跳两层)
    即 `K(N) = K(N - 1) + K(N - 2)`,也就是一个标准的斐波那契数列
2. 当台阶等于0时，方法为1种，这里需要注意

### 代码

```java
class Solution {
    public int numWays(int n) {
        if (n <= 1) {
            return 1;
        }
        int[] ints = new int[n];
        ints[0] = 1;
        ints[1] = 2;
        for (int i = 2; i < ints.length; i++) {
            ints[i] = (ints[i-1] + ints[i-2]) % 1000000007;
        }
        return ints[n - 1];
    }
}
```