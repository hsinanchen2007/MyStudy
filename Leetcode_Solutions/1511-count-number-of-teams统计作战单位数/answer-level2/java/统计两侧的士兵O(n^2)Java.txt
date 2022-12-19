### 解题思路

遍历中间的士兵，统计 **左边/右边** 比他 **小/大** 的士兵人数。

每名士兵在中间的情况下可以组队的数量为：
**左**边比他**小**的人数 × **右**边比他**大**的人数 + **左**边比他**大**的人数 × **右**边比他**小**的人数

公式为：$\sum_{}(left[0] * right[1] + left[1] * right[0])$

时间复杂度：一个`for`循环为$O(n)$，两次`count`函数$O(n)$，故总的时间复杂度为$O(n^2)$。
空间复杂度：$O(1)$。

### 代码

```java
class Solution {
    public int numTeams(int[] rating) {
        int n = rating.length;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int[] left = count(rating, 0, i, rating[i]);
            int[] right = count(rating, i, n, rating[i]);
            result += left[0] * right[1] + left[1] * right[0];
        }
        return result;
    }

    private int[] count(int[] rating, int from, int to, int key) {
        int[] results = new int[2];
        for (int i = from; i < to; ++i) {
            if (rating[i] < key) {
                ++results[0];
            } else if (rating[i] > key) {
                ++results[1];
            }
        }
        return results;
    }
}
```

![QQ截图20200329155104.jpg](https://pic.leetcode-cn.com/6c32ebaf4db504f6b818ec9f226c07806996d340810bea9a48a8a04eb6c2c729-QQ%E6%88%AA%E5%9B%BE20200329155104.jpg)
