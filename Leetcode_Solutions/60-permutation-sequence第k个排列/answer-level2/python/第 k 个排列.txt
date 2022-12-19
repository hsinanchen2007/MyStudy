#### 解决方案

面试中主要有三种类型的排列问题：

- 1. 全排列

- 2. [下一个排列](https://leetcode-cn.com/articles/next-permutation/)

- 3. 第 k 个排列（当前问题）

如果排列的顺序不重要，可以使用“交换”的思想回溯写出全排列。生成 $N!$ 个全排列需要时间 $\mathcal{O}(N \times N!)$。该算法可以解决第一类问题。

D.E. Knuth 算法按照字典顺序生成全排列，在 $\mathcal{O}(N)$ 时间内完成。该算法可以解决第二类问题。

但是这两个算法不能解决第三类问题：

- 良好的时间复杂度，即无回溯。

- 先前排列未知，即不能使用 D.E. Knuth 算法。

为了解决这两个问题，可以使用映射的思路，因为生成数字的排列更容易。

> 使用数字生成排列，然后映射到组合/子集/排列中。

这种方法也广泛用于密码破解算法。


#### 方法一：阶乘数系统

**为什么需要阶乘数系统**

排列的每种情况都可以使用十进制或二进制数表示：

$$
k = \sum\limits_{m = 0}^{N - 1}{k_m 2^m}, \qquad 0 \le k_m \le 1 
$$

原理如下：

![](https://pic.leetcode-cn.com/Figures/60/subsets.png)

排列的问题在于排列的所有情况可能比数字表示的范围更大。$N$ 个元素的全排列数量为 $N!$，$N$ 位二进制包含 $2^N$ 个不同的数字。简单使用二进制数作为解空间不能包含排列的所有情况。

因此使用阶乘数系统，它具有非恒定基数：

$$
k = \sum\limits_{m = 0}^{N - 1}{k_m m!}, \qquad 0 \le k_m \le m 
$$
 
注意：权重的大小不恒定，而是取决于基数：当 $0 \le k_m \le m$ 时基数为 $m!$。例如：$k_0 = 0$，$0 \le k_1 \le 1$，$0 \le k_2 \le 2$ 等等。

映射方式如下：

![](https://pic.leetcode-cn.com/Figures/60/permutations2.png)

现在映射全部排列情况。从排列数 $k = 0 = \sum\limits_{m = 0}^{N - 1}{0 \times m!}$ 到排列数 $N! - 1$：$k = N! - 1 = \sum\limits_{m = 0}^{N - 1}{m \times m!}$。

> 现在使用这些阶乘数构造全部的排列。

**如何从阶乘构造排列**

$N = 3$ 时，输入数组为 `nums = [1, 2, 3]`，$k = 3$。但是排列的编号为从 $0$ 到 $N! - 1$，而不是从 $1$ 到 $N!$。因此 $N = 3$ 时，$k = 2$。

首先构造 $k = 2$ 的阶乘数：

$$
k = 2 = 1 \times 2! + 0 \times 1! + 0 \times 0! = (1, 0, 0)
$$

> 阶乘中的系数表示输入数组中，除去已使用元素的索引。这符合每个元素只能在排列中出现一次的要求。

![](https://pic.leetcode-cn.com/Figures/60/index.png)

第一个数字是 `1`，即排列中的第一个元素是 `nums[1] = 2`。由于每个元素只能使用一次，则从 `nums` 中删除该元素。

![](https://pic.leetcode-cn.com/Figures/60/step1.png)

阶乘中下一个系数为 `0`，即排列中 `nums[0] = 1`，然后从 `nums` 中删除该元素。

![](https://pic.leetcode-cn.com/Figures/60/step2.png)

阶乘中下一个系数也是 `0`，即排列中 `nums[0] = 3`，然后从 `nums` 中删除该元素。

![](https://pic.leetcode-cn.com/Figures/60/step3.png)

**算法**

- 生成输入数组，存储从 $1$ 到 $N$ 的数字。

- 计算从 $0$ 到 $(N - 1)!$ 的所有阶乘数。

- 在 $(0, N! - 1)$ 区间内，$k$ 重复减 $1$。

- 计算 $k$ 的阶乘，使用阶乘系数构造排列。

- 返回排列字符串。

```python [solution1-Python]
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        factorials, nums = [1], ['1']
        for i in range(1, n):
            # generate factorial system bases 0!, 1!, ..., (n - 1)!
            factorials.append(factorials[i - 1] * i)
            # generate nums 1, 2, ..., n
            nums.append(str(i + 1))
        
        # fit k in the interval 0 ... (n! - 1)
        k -= 1
        
        # compute factorial representation of k
        output = []
        for i in range(n - 1, -1, -1):
            idx = k // factorials[i]
            k -= idx * factorials[i]
            
            output.append(nums[idx])
            del nums[idx]
        
        return ''.join(output)
```

```java [solution1-Java]
class Solution {
  public String getPermutation(int n, int k) {
    int[] factorials = new int[n];
    List<Integer> nums = new ArrayList() {{add(1);}};

    factorials[0] = 1;
    for(int i = 1; i < n; ++i) {
      // generate factorial system bases 0!, 1!, ..., (n - 1)!
      factorials[i] = factorials[i - 1] * i;
      // generate nums 1, 2, ..., n
      nums.add(i + 1);
    }

    // fit k in the interval 0 ... (n! - 1)
    --k;

    // compute factorial representation of k
    StringBuilder sb = new StringBuilder();
    for (int i = n - 1; i > -1; --i) {
      int idx = k / factorials[i];
      k -= idx * factorials[i];

      sb.append(nums.get(idx));
      nums.remove(idx);
    }
    return sb.toString();
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N^2)$，从列表中删除元素，共执行操作次数：

$$
N + (N - 1) + ... + 1 = N(N - 1)/2
$$ 
    
* 空间复杂度：$\mathcal{O}(N)$。