#### 方法一：枚举

我们可以枚举数组中的每一个元素，对于当前枚举的元素 `x`，它可以和 `x + 1` 组成和谐子序列。我们再遍历一遍整个数组，找出等于 `x` 或 `x + 1` 的元素个数，就可以得到以 `x` 为最小值的和谐子序列的长度。

<![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_1Slide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_1Slide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_1Slide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_1Slide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_1Slide5.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_1Slide6.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_1Slide7.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_1Slide8.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_1Slide9.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_1Slide10.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_1Slide11.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_1Slide12.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_1Slide13.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_1Slide14.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_1Slide15.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_1Slide16.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_1Slide17.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_1Slide18.PNG)>

```Java [sol1]
public class Solution {
    public int findLHS(int[] nums) {
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            int count = 0;
            boolean flag = false;
            for (int j = 0; j < nums.length; j++) {
                if (nums[j] == nums[i])
                    count++;
                else if (nums[j] + 1 == nums[i]) {
                    count++;
                    flag = true;
                }
            }
            if (flag)
                res = Math.max(count, res);
        }
        return res;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N^2)$，其中 $N$ 是数组的长度。

* 空间复杂度：$O(1)$。

#### 方法二：哈希映射

在方法一中，我们枚举了 `x` 后，遍历数组找出所有的 `x` 和 `x + 1`。我们也可以用一个哈希映射（HashMap）来存储每个数出现的次数，这样就能在 $O(1)$ 的时间内得到 `x` 和 `x + 1` 出现的次数。

我们首先遍历一遍数组，得到哈希映射。随后遍历哈希映射，设当前遍历到的键值对为 `(x, value)`，那么我们就查询 `x + 1` 在哈希映射中对应的值，就得到了 `x` 和 `x + 1` 出现的次数。

<![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_2Slide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_2Slide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_2Slide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_2Slide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_2Slide5.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_2Slide6.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_2Slide7.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_2Slide8.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_2Slide9.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_2Slide10.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_2Slide11.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_2Slide12.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_2Slide13.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_2Slide14.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_2Slide15.PNG)>


```Java [sol2]
public class Solution {
    public int findLHS(int[] nums) {
        HashMap < Integer, Integer > map = new HashMap < > ();
        int res = 0;
        for (int num: nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        for (int key: map.keySet()) {
            if (map.containsKey(key + 1))
                res = Math.max(res, map.get(key) + map.get(key + 1));
        }
        return res;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是数组的长度。

* 空间复杂度：$O(N)$，用来存储哈希映射。

#### 方法三：哈希映射 + 单次扫描

在方法二中，我们需要对数组进行一次扫描，再对哈希映射进行一次扫描。事实上，我们也可以设计出只进行一次扫描的算法。

我们扫描一次数组，当扫描到元素 `x` 时，我们首先将 `x` 加入哈希映射，随后获取哈希映射中 `x - 1, x, x + 1` 三者出现的次数 `u, v, w`，那么 `u + v` 即为 `x - 1, x` 组成的和谐子序列的长度，`v + w` 即为 `x, x + 1` 组成的和谐子序列的长度。假设数组中最长的和谐子序列的最后一个元素在数组中的位置为 `i`，那么在扫描到 `nums[i]` 时，`u + v` 和 `v + w` 中一定有一个就是答案。因此这种方法可以找到最长的和谐子序列的长度。

<![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_3Slide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_3Slide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_3Slide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_3Slide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_3Slide5.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_3Slide6.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_3Slide7.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_3Slide8.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_3Slide9.PNG),![1000](https://pic.leetcode-cn.com/Figures/594_Harmonic_Subsequence_3Slide10.PNG)>


```Java [sol3]
public class Solution {
    public int findLHS(int[] nums) {
        HashMap < Integer, Integer > map = new HashMap < > ();
        int res = 0;
        for (int num: nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
            if (map.containsKey(num + 1))
                res = Math.max(res, map.get(num) + map.get(num + 1));
            if (map.containsKey(num - 1))
                res = Math.max(res, map.get(num) + map.get(num - 1));
        }
        return res;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是数组的长度。

* 空间复杂度：$O(N)$，用来存储哈希映射。