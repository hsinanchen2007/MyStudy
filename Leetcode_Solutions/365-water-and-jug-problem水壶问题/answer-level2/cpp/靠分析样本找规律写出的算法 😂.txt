说来惭愧，我刚看到示例1（参数是 3, 5, 4）的时候就卡住了，想了好久才明白是怎么回事。后来我又试了其他例子，发现“倒法”各不相同，有些甚至很难想（比如 5，8，1 的输出是 true ）。于是隐隐觉得把这些千奇百怪的“倒法”模拟出来是不太可能了，同时，小时候做数学选择题经常用的“枚举法”思想开始逐渐涌入心头。

果不其然，通过观察示例2，我很快就发现了一个重要规律，那就是两个容量为偶数的水壶，只能得到偶数升的水。道理很简单，两个偶数无论怎么加减，都不会得到奇数。

然后开始分析容量有奇数的情况，这个过程相当漫长且痛苦。我不断地观察 x, y, z 的大小、差值、倍数等各种关系，在经历了 3 次提交错误后，居然莫名其妙地通过了，很神奇！

一看结果，在时间和空间上都击败了 100% 的用户，这可是我的第一次。激动之余，我毅然决然地决定写一篇题解。

```
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z == 0 || z == x || z == y) {
            return true;
        }
        int sum = x + y;
        if (sum < z) {
            return false;
        } else if (sum == z) {
            return true;
        } else {
            if (x == y) {
                return false; // 两个水壶一样，就相当于是一个水壶
            }
            if (x % 2 == 0 && y % 2 == 0) { // 两个偶数，只能获得偶数升
                return z % 2 == 0;
            }
            int difference = y - x;
            if (difference < 0) {
                difference = -difference;
            }
            if (x % difference != 0 && y % difference != 0) {
                return true;
            }
            return z % x == 0 || z % y == 0 || z % difference == 0;
        }

    }
};
```
