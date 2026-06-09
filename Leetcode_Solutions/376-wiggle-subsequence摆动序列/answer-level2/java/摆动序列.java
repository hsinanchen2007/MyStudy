### 概要

我们需要找到最长摆动序列。一个摆动序列是一个上升下降交替的子序列。

#### 方法 1：暴力

我们去找所有可能摆动子序列的长度并找到它们中的最大值。为了实现这样的算法，我们需要一个回溯函数， $\text{calculate}(\text{nums}, \text{index}, \text{isUp})$ ，将 $\text{nums}$ 作为输入数组，$text{index}$ 记录的是我们从哪个位置开始找最长摆动序列， boolean 变量 $\text{isUp}$ 记录的是现在要找的是上升元素还是下降元素。如果函数 $\text{calculate}$ 在一个上升摆动之后被调用，我们需要用这个相同的函数找到下降的元素。如果 $\text{calculate}$ 在一个下降元素之后被调用，那么我们需要用这个函数找到下一个上升的元素。

```java [-Java]
public class Solution {
    private int calculate(int[] nums, int index, boolean isUp) {
        int maxcount = 0;
        for (int i = index + 1; i < nums.length; i++) {
            if ((isUp && nums[i] > nums[index]) || (!isUp && nums[i] < nums[index]))
                maxcount = Math.max(maxcount, 1 + calculate(nums, i, !isUp));
        }
        return maxcount;
    }

    public int wiggleMaxLength(int[] nums) {
        if (nums.length < 2)
            return nums.length;
        return 1 + Math.max(calculate(nums, 0, true), calculate(nums, 0, false));
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n!)$ 。 $\text{calculate}()$ 会被调用 $n!$ 次。
* 空间复杂度： $O(n)$ 。回溯深度为 $n$ 。

#### 方法 2：动态规划

**算法**

为了更好地理解这一方法，用两个数组来 dp ，分别记作 $up$ 和 $down$ 。

每当我们选择一个元素作为摆动序列的一部分时，这个元素要么是上升的，要么是下降的，这取决于前一个元素的大小。

$up[i]$ 存的是目前为止最长的以第 $i$ 个元素结尾的上升摆动序列的长度。

类似的， $down[i]$ 记录的是目前为止最长的以第 $i$ 个元素结尾的下降摆动序列的长度。

我们每当找到将第 $i$ 个元素作为上升摆动序列的尾部的时候就更新 $up[i]$ 。现在我们考虑如何更新 $up[i]$ ，我们需要考虑前面所有的降序结尾摆动序列，也就是找到 $down[j]$ ，满足 $j < i$ 且 $nums[i] >nums[j]$ 。类似的， $down[i]$ 也会被更新。

```java []
public class Solution {
    public int wiggleMaxLength(int[] nums) {
        if (nums.length < 2)
            return nums.length;
        int[] up = new int[nums.length];
        int[] down = new int[nums.length];
        for (int i = 1; i < nums.length; i++) {
            for(int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    up[i] = Math.max(up[i],down[j] + 1);
                } else if (nums[i] < nums[j]) {
                    down[i] = Math.max(down[i],up[j] + 1);
                }
            }
        }
        return 1 + Math.max(down[nums.length - 1], up[nums.length - 1]);
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n^2)$ 。 循环内嵌套了一个循环。
* 空间复杂度： $O(n)$ 。 dp 需要两个同样长度的数组。

#### 方法 3：线性动态规划

**算法**

数组中的任何元素都对应下面三种可能状态中的一种：

1. 上升的位置，意味着 $nums[i] > nums[i - 1]$
2. 下降的位置，意味着 $nums[i] < nums[i - 1]$
3. 相同的位置，意味着 $nums[i] == nums[i - 1]$

更新的过程如下：

如果 $nums[i] > nums[i-1]$ ，意味着这里在摆动上升，前一个数字肯定处于下降的位置。所以 $up[i] = down[i-1] + 1$ ， $down[i]$ 与 $down[i-1]$ 保持相同。

如果 $nums[i] < nums[i-1]$ ，意味着这里在摆动下降，前一个数字肯定处于下降的位置。所以 $down[i] = up[i-1] + 1$ ， $up[i]$ 与 $up[i-1]$ 保持不变。

如果 $nums[i] == nums[i-1]$ ，意味着这个元素不会改变任何东西因为它没有摆动。所以 $down[i]$ 与 $up[i]$ 与 $down[i-1]$ 和 $up[i-1]$ 都分别保持不变。

最后，我们可以将 $up[length-1]$ 和 $down[length-1]$ 中的较大值作为问题的答案，其中 $length$ 是给定数组中的元素数目。

下面的例子可以说明这一过程：

<![image.png](https://pic.leetcode-cn.com/1b1c1d8b5bc1cf0d5fe4e87496941b940b58eec2c96a966713e932dc6fd93a71-image.png),![image.png](https://pic.leetcode-cn.com/57921a1569c7152e1196df5719421d24c14f5ca7228a33388818a50ab0a7396f-image.png),![image.png](https://pic.leetcode-cn.com/3ad6aa325738693640ac2220db2a3dedac99f031391e92bef3bcf4fda14159d1-image.png),![image.png](https://pic.leetcode-cn.com/0d5c0cf304d6446c7033bfae76fe1a02f425b97d68f0e3df63a83db271fda8d8-image.png),![image.png](https://pic.leetcode-cn.com/31322f4dce5f31eac88b85a092684a005d4a29a497f68925e9958ce1be9bec68-image.png),![image.png](https://pic.leetcode-cn.com/18a3945b6151494ed2996d3b0ce40eb60dda5022cdbc51542cbdd76a2fa98ac0-image.png),![image.png](https://pic.leetcode-cn.com/b2f5c6e3e9b9e72ba819804bdfaecb3a91f9ec392c13f43e02744b90b56a5334-image.png),![image.png](https://pic.leetcode-cn.com/a8b2794d58d39bc9d6610a34451e6ff4f45034c9619fd3ef78cdc9aa9a0d926f-image.png),![image.png](https://pic.leetcode-cn.com/60a89097fadc46b082e8786d717d8583a62bc35b6dc88eccc1a28a8b1ca54d8b-image.png),![image.png](https://pic.leetcode-cn.com/386e47e21d11df26a87aea99e522a978a1e7db5f1f0283dec3a26badbcd08aa2-image.png),![image.png](https://pic.leetcode-cn.com/96e00e72b2626f4c222a58d20b103a55cbcfca6bc4945072bc0121e92ed94030-image.png),![image.png](https://pic.leetcode-cn.com/7af00142293a9087a99ba9ed3ac6d7899db265f32eba111b8ed73d095e2a625f-image.png)>

```java [-Java]
public class Solution {
    public int wiggleMaxLength(int[] nums) {
        if (nums.length < 2)
            return nums.length;
        int[] up = new int[nums.length];
        int[] down = new int[nums.length];
        up[0] = down[0] = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1]) {
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];
            } else if (nums[i] < nums[i - 1]) {
                down[i] = up[i - 1] + 1;
                up[i] = up[i - 1];
            } else {
                down[i] = down[i - 1];
                up[i] = up[i - 1];
            }
        }
        return Math.max(down[nums.length - 1], up[nums.length - 1]);
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n)$ 。只需要遍历数组一遍。
* 空间复杂度： $O(n)$ 。 dp需要两个相同长度的数组。


#### 方法 4： 空间优化的动态规划

**算法**

这个方法与方法 3 一样。但我们观察可以发现， DP 过程中更新 $up[i]$ 和 $down[i]$ ，其实只需要 $up[i-1]$ 和 $down[i-1]$ 。因此，我们可以通过只记录最后一个元素的值而不使用数组来节省空间。

```java [-Java]
public class Solution {
    public int wiggleMaxLength(int[] nums) {
        if (nums.length < 2)
            return nums.length;
        int down = 1, up = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1])
                up = down + 1;
            else if (nums[i] < nums[i - 1])
                down = up + 1;
        }
        return Math.max(down, up);
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n)$ 。仅遍历数组一次。
* 空间复杂度： $O(1)$ 。只使用了常数级别的额外空间。

#### 方法 5：贪心

**算法**

我们其实不需要 dp 来解决这个问题。这个问题等价于找数组中交替的最大最小值。因此，如果我们选择中间的数字作为摆动序列的一部分，只会导致序列小于等于只选连续的最大最小元素。

下图可以更好地说明此方法：
![image.png](https://pic.leetcode-cn.com/ff38066bef00568e0a9c206b781413660f01a2f5f64254e69624fd4b1e8fab45-image.png)


从上图中，我们可以看到，如果我们选择 **C** 而不是 **D** 作为摆动序列的第二个点，我们无法将点 **E** 也包括进最终序列。因此，我们无法得到最长摆动序列。

因此，为了解决这个问题，我们维护一个变量 $\text{prevdiff}$ ，它的作用是只是当前数字的序列是上升还是下降的。如果 $\text{prevdiff} > 0$ ，那么表示目前是上升序列，我们需要找一个下降的元素。因此，我们更新已找到的序列长度 $\text{diff}$ （$nums[i]-nums[i-1]$）为负数。类似的，如果 $\text{prevdiff} < 0$ ，我们就更新 $\text{diff}$ （$nums[i]-nums[i-1]$）为正数。

当整个数组都被遍历后，我们得到了最终的结果，它就是最长摆动子序列的长度。

```java [-Java]
public class Solution {
    public int wiggleMaxLength(int[] nums) {
        if (nums.length < 2)
            return nums.length;
        int prevdiff = nums[1] - nums[0];
        int count = prevdiff != 0 ? 2 : 1;
        for (int i = 2; i < nums.length; i++) {
            int diff = nums[i] - nums[i - 1];
            if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) {
                count++;
                prevdiff = diff;
            }
        }
        return count;
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n)$ 。我们需要遍历数组一次。

* 空间复杂度： $O(1)$ 。不需要使用额外的空间。
