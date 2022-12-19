#### 方法一：暴力解法 【超出时间限制】

**算法**

首先需要知道 $i$，$j$ 和 $k$ 的取值范围，下图显示了 $i$，$j$ 和 $k$ 能够取得的最小值和最大值。

![分割数组](https://pic.leetcode-cn.com/Figures/638_Split_Array.PNG){:width=480}


长度为 $n$ 的数组，$i$，$j$ 和 $k$ 的取值分别为：

$1 \le i \le n-6$

$i+2 \le j \le n-4$

$j+2 \le k \le n-2$

在 $i$，$j$ 和 $k$ 满足取值条件的情况下，遍历数组 $num$，计算所有可能的分割情况，检查每种分割情况是否满足题意。

```java [solution1-Java]
public class Solution {

    public int sum(int[] nums, int l, int r) {
        int summ = 0;
        for (int i = l; i < r; i++)
            summ += nums[i];
        return summ;
    }

    public boolean splitArray(int[] nums) {
        if (nums.length < 7)
            return false;
        for (int i = 1; i < nums.length - 5; i++) {
            int sum1 = sum(nums, 0, i);
            for (int j = i + 2; j < nums.length - 3; j++) {
                int sum2 = sum(nums, i + 1, j);
                for (int k = j + 2; k < nums.length - 1; k++) {
                    int sum3 = sum(nums, j + 1, k);
                    int sum4 = sum(nums, k + 1, nums.length);
                    if (sum1 == sum2 && sum3 == sum4 && sum2 == sum4)
                        return true;
                }
            }
        }
        return false;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n^4)$，四层 for 循环。最坏的情况下，每层循环的复杂度都是 $O(n)$。

* 空间复杂度：$O(1)$，恒定的额外空间。


#### 方法二：累加和 【超出时间限制】

**算法**

暴力解法需要求解每个子数组的和。该方法中使用累加和数组计算每个子数组的和，以提高计算效率。其中 $sum[i]$ 存储数组 $nums$ 从 $0$ 开始，直到第 $i$ 个元素的累加和。因此 $sum\big(subarray(i:j)\big)$ 等于 $sum[j]-sum[i]$。

```java [solution2-Java]
public class Solution {
    public boolean splitArray(int[] nums) {
        if (nums.length < 7)
            return false;
        int[] sum = new int[nums.length];
        sum[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
        for (int i = 1; i < nums.length - 5; i++) {
            int sum1 = sum[i - 1];
            for (int j = i + 2; j < nums.length - 3; j++) {
                int sum2 = sum[j - 1] - sum[i];
                for (int k = j + 2; k < nums.length - 1; k++) {
                    int sum3 = sum[k - 1] - sum[j];
                    int sum4 = sum[nums.length - 1] - sum[k];
                    if (sum1 == sum2 && sum3 == sum4 && sum2 == sum4)
                        return true;
                }
            }
        }
        return false;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n^3)$，三层 for 循环，与计算累加和。

* 空间复杂度：$O(n)$，累积和数组 $sum$ 长度为 $n$。


#### 方法三：改进的累加和 【超出时间限制】

**算法**

在 *方法二* 中，如果第一个子数组和第二个子数组的和不相等，则直接停止后面的运算，这在一定程度上提高了 *方法二* 的计算效率。

```java [solution3-Java]
public class Solution {
    public boolean splitArray(int[] nums) {
        if (nums.length < 7)
            return false;

        int[] sum = new int[nums.length];
        sum[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
        for (int i = 1; i < nums.length - 5; i++) {
            int sum1 = sum[i - 1];
            for (int j = i + 2; j < nums.length - 3; j++) {
                int sum2 = sum[j - 1] - sum[i];
                if (sum1 != sum2)
                    continue;
                for (int k = j + 2; k < nums.length - 1; k++) {
                    int sum3 = sum[k - 1] - sum[j];
                    int sum4 = sum[nums.length - 1] - sum[k];
                    if (sum3 == sum4 && sum2 == sum4)
                        return true;
                }
            }
        }
        return false;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n^3)$，三层 for 循环。

* 空间复杂度：$O(n)$，累积和数组 $sum$ 长度为 $n$。


#### 方法四：使用 HashMap 【超出时间限制】

**算法**

本方法中，使用 $map$ 存储数据，其数据格式为：

$\big\{csum(i):[i_1,i_2,i_3,....]\big\}$，其中 $csum(i)$ 表示数组 $nums$ 的前 $i$ 项累加和，$[i_1,i_2,i_3,....]$ 表示该累加和对应序列的最后一个元素索引，即满足 $sum=csum(i)$ 的所有 $i$。

然后考虑 $i$ 和 $j$ 的位置。数组前 $j-1$ 项累加和为：

$$
csum(j-1)=sum(part1) + nums[i] + sum(part2)
$$

如果前两个子数组的累加和相等，则有 

$$
csum'(j-1) = csum(i-1) + nums[i] + csum(i-1) = 2csum(i-1) + nums[i]
$$

遍历数组 $nums$，确定第一个分割点 $i$ 的位置，然后在 $map$ 中查找所有满足 $csum'(j-1) = 2csum(i-1) + nums[i]$ 的 $j$。再遍历所有的 $j$，寻找第三个分割点，使得第三个和第四个子数组的累加和与第一个子数组累加和相同。

与前面类似，数组前 $k-1$ 个元素的累加和为：

$$
csum(k-1) = sum(part1) + nums[i] + sum(part2) + nums[j] + sum(part3)
$$

为了保证第三个子数组的累加和与前两个子数组相同，必须满足：

$$
csum'(k-1) = 3*csum(i-1) + nums[i] + nums[j]
$$

数组 $nums$ 所有元素的累加和为：

$$
csum(end) = sum(part1) + nums[i] + sum(part2) + nums[j] + sum(part3) + nums[k] + sum(part4)
$$

同理，为了保证第四个子数组的累加和与前三个子数组相同，必须满足：

$$
csum'(end) = 4*csum(i-1) + nums[i] + nums[j] + nums[k]
$$

对于每种分割情况，只需要在 $map$ 中查找是否存在满足条件的累加和即可，不需要遍历所有的 $(i, j, k)$ 组合，也不需要计算每个子数组的累加和。因此，这大大减少了计算量。

```java [solution4-Java]
public class Solution {
    public boolean splitArray(int[] nums) {
        HashMap < Integer, ArrayList < Integer >> map = new HashMap < > ();
        int summ = 0, tot = 0;
        for (int i = 0; i < nums.length; i++) {
            summ += nums[i];
            if (map.containsKey(summ))
                map.get(summ).add(i);
            else {
                map.put(summ, new ArrayList < Integer > ());
                map.get(summ).add(i);
            }
            tot += nums[i];
        }
        summ = nums[0];
        for (int i = 1; i < nums.length - 5; i++) {
            if (map.containsKey(2 * summ + nums[i])) {
                for (int j: map.get(2 * summ + nums[i])) {
                    j++;
                    if (j > i + 1 && j < nums.length - 3 && map.containsKey(3 * summ + nums[i] + nums[j])) {
                        for (int k: map.get(3 * summ + nums[j] + nums[i])) {
                            k++;
                            if (k < nums.length - 1 && k > j + 1 && 4 * summ + nums[i] + nums[j] + nums[k] == tot)
                                return true;
                        }
                    }
                }
            }
            summ += nums[i];
        }
        return false;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n^3)$，三层嵌套循环。最坏情况下，每层循环的复杂度都是 $O(n)$，例如 [0,0,0....,1,1,1,1,1,1,1]。

* 空间复杂度：$O(n)$，大小为 $n$ 的 HashMap。


#### 方法五：HashSet+累加和 【通过】

**算法**

本方法中，首先计算累加和数组 $sum$，其中 $sum[i]$ 表示数组 $nums$ 前 $i$ 项和。然后遍历第二个分割点 $j$ 所有可能的位置。对每一个 $j$，首先计算其左边分割点的位置 $i$，使得第一个子数组和第二个子数组的和相等，即满足 $sum[i-1] = sum [j-1] - sum[i]$，并将该累加和存储到 HashSet 中（对每个 $j$，都会创建一个新的 HashSet）。因此，HashSet 中的累加和表示当中间分割点为 $j$ 时，怎样的累加和会让第一个子数组和第二个子数组之和相等。

然后计算 $j$ 右边分割点 $k$ 的位置，使得第三个子数组的和与第四个子数组的和相等，即满足 $sum[n-1]-sum[k]=sum[k-1] - sum[j]$。再到 HashSet 中查找是否存在相等的子数组和。如果存在，则找到满足条件的三元组 $(i, j, k)$，否则不存在这样的分割方法。

下面过程展示了一个寻找分割点的例子：

<![1200](https://pic.leetcode-cn.com/Figures/548_Split_ArraySlide1.PNG),![1200](https://pic.leetcode-cn.com/Figures/548_Split_ArraySlide2.PNG),![1200](https://pic.leetcode-cn.com/Figures/548_Split_ArraySlide3.PNG),![1200](https://pic.leetcode-cn.com/Figures/548_Split_ArraySlide4.PNG),![1200](https://pic.leetcode-cn.com/Figures/548_Split_ArraySlide5.PNG),![1200](https://pic.leetcode-cn.com/Figures/548_Split_ArraySlide6.PNG),![1200](https://pic.leetcode-cn.com/Figures/548_Split_ArraySlide7.PNG),![1200](https://pic.leetcode-cn.com/Figures/548_Split_ArraySlide8.PNG),![1200](https://pic.leetcode-cn.com/Figures/548_Split_ArraySlide9.PNG),![1200](https://pic.leetcode-cn.com/Figures/548_Split_ArraySlide10.PNG)>

```java [solution5-Java]
public class Solution {
    public boolean splitArray(int[] nums) {
        if (nums.length < 7)
            return false;
        int[] sum = new int[nums.length];
        sum[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
        for (int j = 3; j < nums.length - 3; j++) {
            HashSet < Integer > set = new HashSet < > ();
            for (int i = 1; i < j - 1; i++) {
                if (sum[i - 1] == sum[j - 1] - sum[i])
                    set.add(sum[i - 1]);
            }
            for (int k = j + 2; k < nums.length - 1; k++) {
                if (sum[nums.length - 1] - sum[k] == sum[k - 1] - sum[j] && set.contains(sum[k - 1] - sum[j]))
                    return true;
            }
        }
        return false;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n^2)$，一个外层循环和两个内层循环。

* 空间复杂度：$O(n)$，大小为 $n$ 的 HashSet。