![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/0faeea82fd7c1c07d79948850d96b28a1b7c2299d5da132a72c26a5a8daa5b04-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)

### 代码

```java
class Solution {
    public int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int x = 0;
        int y = 1;
        int tmp = 0;
        for (int i = 0; i < n - 1; i++) {
            tmp = x;
            x = y % 1000000007;
            y = (tmp + y) % 1000000007;
        }
        return y;
    }
}
```