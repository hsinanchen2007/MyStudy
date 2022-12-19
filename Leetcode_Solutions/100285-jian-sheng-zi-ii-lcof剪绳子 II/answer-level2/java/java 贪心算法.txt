![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/eb3d59398bcbfcde274b9ea9b2725584546a1603a808922f71d974421a510a41-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)


### 代码

```java
class Solution {
    //用贪心算法来求解
    public int cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        long res = 1L;
        while (n >= 5) {
            n -= 3;
            res = (res * 3) % 1000000007;
        }
        return (int) ((res * n) % 1000000007);
    }
}
```