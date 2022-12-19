### 解题思路

基于尾递归的算法经编译器优化后，可以像普通循环一样快。

### 代码

```java []
class Solution {
    public int fib(int n) {
        return fibsHelper(n, 0, 0, 1);
    }

    public int fibsHelper(int n, int i, int acc1, int acc2) {
        if (i == n) {
            return acc1;
        } else {
            return fibsHelper(n, i + 1, acc2, (acc1 + acc2) % 1000000007);
        }
    }
}
```
```scala []
object Solution {
    def fib(n: Int): Int = {
        fibsHelper(n, 0, 0, 1)
    }

    def fibsHelper(thershold: Int, cur: Int, acc1: Int, acc2: Int): Int = {
        if (cur == thershold)  acc1
        else {
            fibsHelper(thershold, cur + 1, acc2, (acc1 + acc2) % 1000000007)
        }
    }
}
```