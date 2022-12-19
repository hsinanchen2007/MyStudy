![题解.PNG](https://pic.leetcode-cn.com/0d2a2d222b0738a98b051c542c74ee7f45540e4db41187c14ad7b85fec2faf05-%E9%A2%98%E8%A7%A3.PNG)

### 解题思路
因为第 n 项，需要第 (n-1) 项与第 (n-2) 项之和，所以直接创建一个内存为 2 的数组，将第 n 项写在第 (n-2) 项之中，一直如此，最后数组里面只剩下第 (n-1) 项与第 n 项。
到最后return一个第 n 项。
### 代码

```java
class Solution {
    public int fib(int n) {
        int[] a = {0,1};
        for(int i = 2;i<=n;i++) {
            a[i%2] = (a[(i+1)%2] + a[i%2])%1000000007;
        }
        return a[n%2];
    }
}
```