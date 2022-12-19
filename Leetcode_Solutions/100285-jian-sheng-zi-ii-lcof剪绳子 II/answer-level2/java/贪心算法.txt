![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/c029e3c71df677a0d98d7e8d122f782c6b10cd27ee9af0aa302fd5368ce71b9a-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)


### 代码

```java
class Solution {
    public int cuttingRope(int n) {
        //用贪心算法，当n=5，6，7，8，9.。。。的时候
        //(n-3)*3>(n-2)*2>n
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        long res = 1L;
        while (n >= 5) {
            res = res * 3 % 1000000007;
            n = n - 3;
        }
        res = res * n % 1000000007;
        return (int) res;
    }
}
```