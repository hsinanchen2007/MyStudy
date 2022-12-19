![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/c217590567a8f3f29801f4ba8f5ec30c92123b02e02b3bba2e768d0255e6e868-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)


### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int[] contain = new int[10000];
        // 计数，记录每个数出现了几次
        for (int num : deck) {
            contain[num]++;
        }
        int g = -1;
        // 求次数的最大公约数
        for (int num : contain) {
            if (num > 0) {
                if (g == -1) {
                    g = num;
                } else {
                    g = gcd(g, num);
                }
            }
        }
        return g >= 2;
    }

    public int gcd(int x, int y) {
        if (x == 0) return y;
        else return gcd(y % x, x);
    }
}
```