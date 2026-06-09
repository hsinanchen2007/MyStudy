#### 方法 1：暴力 [Time Limit Exceeded]

**算法**

暴力方法非常简单。我们考虑给定数组的每一个可能的子数组并统计里面 0 和 1 的数目。然后，我们找到最长包含相同 0 和 1 数目的子数组。

```Java []
public class Solution {

    public int findMaxLength(int[] nums) {
        int maxlen = 0;
        for (int start = 0; start < nums.length; start++) {
            int zeroes = 0, ones = 0;
            for (int end = start; end < nums.length; end++) {
                if (nums[end] == 0) {
                    zeroes++;
                } else {
                    ones++;
                }
                if (zeroes == ones) {
                    maxlen = Math.max(maxlen, end - start + 1);
                }
            }
        }
        return maxlen;
    }
}

```

**复杂度分析**

* 时间复杂度： $O(n^2)$ 。我们对于每个开始位置，都需要考虑每一个可能的子数组。

* 空间复杂度： $O(1)$ 。只需要 $zeroes$ 和 $ones$ 两个变量。

#### 方法 2：使用额外的数组 [Accepted]

**算法**

这种方法中，我们使用一个变量 $count$ ，用来保存遍历数组过程中到目前为止遇到的 0 和 1 的相对数量。 遇到 $\text{1}$ 的时候， $count$ 变量加 1 ，遇到 0 的时候 $count$ 变量减 1 。

我们从头开始遍历数组，在任何时候，如果 $count$ 变成了 0 ，这表示我们从开头到当前位置遇到的 0 和 1 的数目一样多。另一个需要注意的是，如果我们在遍历数组的过程汇中遇到了相同的 $count$ 2 次，这意味着这两个位置之间 0 和 1 的数目一样多。下图说明了对于数组 `[0 0 1 0 0 0 1 1]` ，是如何求解的：

![image.png](https://pic.leetcode-cn.com/ce11808babb2a9321a336f58d4f00f32d63d55adb7c7e79d0890e164c0e11691-image.png)
{:align="center"}

在上图中， (A,B), (B,C) 和 (A,C) 所代表的子数组含有相同数目的 0 和 1 。

另一个需要注意的地方是最长子序列是 (A,C) 对应的子数组。因此，如果我们记录相同 $count$ 最早出现的位置，我们就可以找到有相同数目的 0 和 1 的最长子数组。

如果数组是全 0 或者全 1 的时候， $count$ 值的可以达到 $\text{-n}$ 和 $\text{n}$ ，所以我们使用一个大小为 ${2n+1}$ 的数组 $arr$ ，以保存所有出现过的 $count$ 值。对于 $arr$ 数组中的每个位置，我们记录对应 $count$ 值第一次出现的位置。我们在后面每次遇到相同的 $count$ 值，我们就利用第一次出现的位置和当前位置来计算对应子数组的长度。

```Java []

public class Solution {

    public int findMaxLength(int[] nums) {
        int[] arr = new int[2 * nums.length + 1];
        Arrays.fill(arr, -2);
        arr[nums.length] = -1;
        int maxlen = 0, count = 0;
        for (int i = 0; i < nums.length; i++) {
            count = count + (nums[i] == 0 ? -1 : 1);
            if (arr[count + nums.length] >= -1) {
                maxlen = Math.max(maxlen, i - arr[count + nums.length]);
            } else {
                arr[count + nums.length] = i;
            }

        }
        return maxlen;
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n)$ 。整个数组只会遍历一遍。

* 空间复杂度： $O(n)$ 。 $arr$ 数组大小为 $\text{2n+1}$ 。

#### 方法 3：使用 HashMap [Accepted]

**算法**

这个方法与前一个方法原理相同，但是我们不使用大小为 $\text{2n+1}$ 的数组因为我们不可能遇到所有的值。因此我们只需要使用一个 HashMap $map$ 来保存所有的 $(index, count)$ 对。对于一个 $count$ ，我们只记录它第一次出现的位置，后面遇到相同的 $count$ 我们都用这个第一次记录的 index 来计算子数组的长度。

下面的动图描述了这一过程：

<![image.png](https://pic.leetcode-cn.com/ee8f18e1fca24b0e857c5a8c463c79e5d94334469d3a153c78af2f107d59c0e3-image.png),![image.png](https://pic.leetcode-cn.com/bf00622ad7478740946335b2b0747f895192f9a4f4465a1d088cd880fe8d42ae-image.png),![image.png](https://pic.leetcode-cn.com/a4a6c3f4ff8cfae17d2ce5c90e73f5e2c5e2ee61e50591163491fcbf1c6675ac-image.png),![image.png](https://pic.leetcode-cn.com/ec2f34ee8a446141a48a4680e77c07eb12f1560f6663891d3fbd6c7575ba4b42-image.png),![image.png](https://pic.leetcode-cn.com/dae2418b8b2211e9956a3f29e7ecf2901226a602867de0d316a2d7f530638cad-image.png),![image.png](https://pic.leetcode-cn.com/c34484b474f959e1aa9a8739044e33de08b505addb6e401cd4036a49044d18d1-image.png),![image.png](https://pic.leetcode-cn.com/2ae4f6101a6f1b9617f7d21d02e5d33c07e461652b8c71946c8a3c2671e96769-image.png),![image.png](https://pic.leetcode-cn.com/96c4a909e1429ee2e8b6bffa065cade8d43c691baf4d095c5dae30e7f728279f-image.png)>

```Java []
public class Solution {

    public int findMaxLength(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int maxlen = 0, count = 0;
        for (int i = 0; i < nums.length; i++) {
            count = count + (nums[i] == 1 ? 1 : -1);
            if (map.containsKey(count)) {
                maxlen = Math.max(maxlen, i - map.get(count));
            } else {
                map.put(count, i);
            }
        }
        return maxlen;
    }
}

```

**复杂度分析**

* 时间复杂度： $O(n)$ 。整个数组遍历一遍。

* 空间复杂度： $O(n)$ 。HashMap $map$ 最大使用空间为 $\text{n}$ ，当且仅当所有元素都是 1 或者 0 。