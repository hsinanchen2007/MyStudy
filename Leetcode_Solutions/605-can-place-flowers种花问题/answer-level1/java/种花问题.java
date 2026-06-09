#### 方法一：贪心

我们从左到右扫描数组 `flowerbed`，如果数组中有一个 `0`，并且这个 `0` 的左右两侧都是 `0`，那么我们就可以在这个位置种花，即将这个位置的 `0` 修改成 `1`，并将计数器 `count` 增加 `1`。对于数组的第一个和最后一个位置，我们只需要考虑一侧是否为 `0`。

在扫描结束之后，我们将 `count` 与 `n` 进行比较。如果 `count >= n`，那么返回 `True`，否则返回 `False`。

```Java [sol1]
public class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int i = 0, count = 0;
        while (i < flowerbed.length) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.length - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                count++;
            }
            i++;
        }
        return count >= n;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是数组 `flowerbed` 的长度。

* 空间复杂度：$O(1)$。

#### 方法二：贪心 + 常数优化

我们可以优化方法一中的常数。在扫描数组 `flowerbed` 时，如果 `count` 的值已经达到 `n`，那么我们可以直接跳出循环并返回 `True`。

```Java [sol2]
public class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int i = 0, count = 0;
        while (i < flowerbed.length) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.length - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i++] = 1;
                count++;
            }
             if(count>=n)
                return true;
            i++;
        }
        return false;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是数组 `flowerbed` 的长度。

* 空间复杂度：$O(1)$。