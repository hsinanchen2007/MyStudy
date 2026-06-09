#### 解题思路：

- 如下图所示，寻找旋转数组的最小元素即为寻找 **右排序数组** 的首个元素 `numbers[x]` ，称 $x$ 为 **旋转点** 。
- 排序数组的查找问题首先考虑使用 **二分法** 解决，其可将遍历法的 *线性级别* 时间复杂度降低至 *对数级别* 。

![Picture1.png](https://pic.leetcode-cn.com/5884538fb9541a31a807d59c81226ded3dcd61df66efcdeb000165036ea68bb9-Picture1.png){:width=400}

##### 算法流程：

1. **循环二分：** 设置 $i$, $j$ 指针分别指向 `numbers` 数组左右两端，$m = (i + j) // 2$ 为每次二分的中点（ "`//`" 代表向下取整除法，因此恒有 $i \leq m < j$ ），可分为以下三种情况：
    1. **当 `numbers[m] > numbers[j]`时：** $m$ 一定在 左排序数组 中，即旋转点 $x$ 一定在 $[m + 1, j]$ 闭区间内，因此执行 $i = m + 1$；
    2. **当 `numbers[m] < numbers[j]` 时：** $m$ 一定在 右排序数组 中，即旋转点 $x$ 一定在$[i, m]$ 闭区间内，因此执行 $j = m$；
    3. **当 `numbers[m] == numbers[j]` 时：** 无法判断 $m$ 在哪个排序数组中，即无法判断旋转点 $x$ 在 $[i, m]$ 还是 $[m + 1, j]$ 区间中。**解决方案：** 执行 $j = j - 1$ 缩小判断范围 *（分析见以下内容）* 。
2. **返回值：** 当 $i = j$ 时跳出二分循环，并返回 `numbers[i]` 即可。

> **思考：** 是否可以用 `numbers[m]` 和 `numbers[i]` 比较做代替？
> **解析：** 不可以。因为做比较的目的是判断 $m$ 在哪个排序数组中。但在 `numbers[m] > numbers[i]`情况下，无法判断 $m$ 在哪个排序数组中。本质是因为 $j$ 初始值肯定在右排序数组中； $i$ 初始值无法确定在哪个排序数组中。
> **示例：** 当 $i = 0, j = 4, m = 2$ 时，有 `numbers[m] > numbers[i]` ，以下两示例得出不同结果。
>    $numbers = [1, 2, 3, 4 ,5]$ 旋转点 $x = 0$ ： $m$ 在右排序数组（此示例只有右排序数组）；
>    $numbers = [3, 4, 5, 1 ,2]$ 旋转点 $x = 3$ ： $m$ 在左排序数组。

##### 展开分析 `numbers[m] == numbers[j]` 情况：

1. **无法判定 $m$ 在左（右）排序数组：** 设以下两个旋转点值为 $0$ 的示例数组，则当 $i = 0$, $j = 4$ 时 $m = 2$ ，两示例结果不同。
    1. 例 $[1, 0, 1, 1, 1]$ ：旋转点 $x = 1$ ，因此 $m = 2$ 在 **右排序数组** 中。
    2. 例 $[1, 1, 1, 0, 1]$ ：旋转点 $x = 3$ ，因此 $m = 2$ 在 **左排序数组** 中。

2. **$j = j - 1$ 操作的正确性证明：** 只需证明每次执行此操作后，旋转点 $x$ 仍在 $[i, j]$ 区间内即可。
    1. **若 $m$ 在右排序数组中：** `numbers[m] == numbers[j]` ，因此数组 $[m, j]$（恒有 $m < j$）区间内所有元素值相等，执行 $j = j - 1$ 只会抛弃一个重复值，因此旋转点 $x$ 仍在 $[i, j]$ 区间内。
    2. **若 $m$ 在左排序数组中：** 由于 `左排序数组 任一元素 >= 右排序数组 任一元素` ，因此可推出旋转点元素值 `numbers[x] <= numbers[j] == numbers[m]`，则有：
        1. **若 `numbers[x] < numbers[j]` ：** 即 $j$ 左方仍有值更小的元素，执行 $j = j - 1$ 后旋转点 $x$ 仍在 $[i, j]$ 区间内。
        2. **若 `numbers[x] == numbers[j]` ：** 分为以下两种情况。
            1. **当 $j>x$ ：** 易得执行 $j = j - 1$ 后旋转点 $x$ 仍在 $[i, j]$ 区间内。
            2. **当 $j=x$：** 特殊情况，即执行 $j = j - 1$ 后旋转点 $x$ **可能不在** $[i, j]$ 区间内。例如 $[1, 1, 1, 2, 3, 1]$ ，当 $i = 0$ , $m = 2$ , $j = 5$ 时执行 $j = j - 1$ 后虽然 *丢失了旋转点索引 $x = 5$* ，但最终返回值仍正确（最终返回的 `numbers[0]` 等于旋转点值 `numbers[5]` ），这是因为：之后的二分循环一直在执行 $j = m$ ，而区间 $[i, m]$ 内的元素值一定都等于旋转点值 `numbers[x]` *（ ∵ 区间内元素值既要满足 $\geq$ 也要满足 $\leq$ `numbers[x]`）* ，因此 **仍可保证正确的返回值** 。

- **总结：** 此方法可以保证返回值 `numbers[i]` 等于旋转点值 `numbers[x]` ；但在少数特例下 $i$ 不是旋转点 $x$ 。本题目只要求返回 “旋转点的值” ，因此本方法可行。

<![Picture2.png](https://pic.leetcode-cn.com/2870326e67a9a1778edc380c5582102cf73a277e39fd7c89de5b8d5dac3853ab-Picture2.png),![Picture3.png](https://pic.leetcode-cn.com/dfed21da64f040ac664b8275c5c57d75d5fd57dda12fd7907bdd8753597edf4d-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/41e849b6d74be968bc604d0f95feb262c30e4238672f4abe4ec32ad4f0d3620b-Picture4.png),![Picture5.png](https://pic.leetcode-cn.com/5fca9d4aafc64134f4587be61f579592de12dd9c510b664999dafaecb3152232-Picture5.png),![Picture6.png](https://pic.leetcode-cn.com/1f6f85498056ebe2fc64ce9952ae54a44c196c69f5c4ed7aba89bc553270afc9-Picture6.png)>

##### 复杂度分析：

- **时间复杂度 $O(log_2 N)$ ：** 在特例情况下（例如 $[1, 1, 1, 1]$），会退化到 $O(N)$。
- **空间复杂度 $O(1)$ ：** $i$ , $j$ , $m$ 指针使用常数大小的额外空间。

#### 代码：

```python []
class Solution:
    def minArray(self, numbers: [int]) -> int:
        i, j = 0, len(numbers) - 1
        while i < j:
            m = (i + j) // 2
            if numbers[m] > numbers[j]: i = m + 1
            elif numbers[m] < numbers[j]: j = m
            else: j -= 1
        return numbers[i]
```

```java []
class Solution {
    public int minArray(int[] numbers) {
        int i = 0, j = numbers.length - 1;
        while (i < j) {
            int m = (i + j) / 2;
            if (numbers[m] > numbers[j]) i = m + 1;
            else if (numbers[m] < numbers[j]) j = m;
            else j--;
        }
        return numbers[i];
    }
}
```