### 解题思路
纪录连续0的个数n, 当n>2时，可插入(n-1)/2个1

### 代码

```java
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        // 连续0出现的起始位置，数组前假设补两位(1,0), 从-1开始纪录
        int start = -1;
        int i;
        for (i = 0; i < flowerbed.length; i++) {
            if (flowerbed[i] == 1) {
                if (i - start > 2) {
                    n -= (i - start - 1) >> 1;
                }
                start = i + 1;
            }
        }
        // 数组后假设补两位(0,1)
        if (i - start >= 2) {
            n -= (i - start) >> 1;
        }
        return n <= 0;
    }
}
```