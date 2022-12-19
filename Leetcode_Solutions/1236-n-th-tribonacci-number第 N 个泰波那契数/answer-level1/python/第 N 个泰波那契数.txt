#### 两种思路：空间优化与性能优化

有两种思路。一种是性能优化，一种是空间优化。

> 首先介绍性能优化

已知 $n$ 小于 38，可以先将斐波那契数列的前 38 项计算出来，保存在一个静态数组中。每次执行测试用例时，直接检索对应数字即可。

> 如何计算斐波那契数列？

两种方法：带记忆的递归和动态计算。这两种方法计算 $N$ 个斐波那契数列都需要 $N$ 步操作。类似 `tribonacci(k) = tribonacci(k - 1) + tribonacci(k - 2) + tribonacci(k - 3)` 这种简单递归不在讨论之列，因为这种递归方法的复杂度达到 $3^N$。

> 初步计算所有斐波那契数保存在静态数组的方法，运行时性能为 $O(1)$，但是需要 $O(N)$ 的空间记录 $N$ 个斐波那契数。在保证性能的同时优化空间也非常重要。

在不允许占用大量空间的情况下，可以使用动态计算的方法，在内存中保留不超过 3 个斐波那契数即可。

![](https://pic.leetcode-cn.com/Figures/1137/methods.png){:width=480}

 
#### 方法一：空间优化：动态计算

- 如果 n < 3，答案可直接得出。

- 否则，初始化前 3 个斐波那契数字 `x = 0, y = z = 1`，并执行 `n - 2` 步循环。循环的每一步：

    - 令 `x = y`。

    - 令 `y = z`。

    - 令 `z = x + y + z`。

- 返回 `z`。

```python [solution1-Python]
class Solution:
    def tribonacci(self, n: int) -> int:
        if n < 3:
            return 1 if n else 0
        
        x, y, z = 0, 1, 1
        for _ in range(n - 2):
            x, y, z = y, z, x + y + z
        return z
```

```java [solution1-Java]
class Solution {
  public int tribonacci(int n) {
    if (n < 3) return n == 0 ? 0 : 1;

    int tmp, x = 0, y = 1, z = 1;
    for (int i = 3; i <= n; ++i) {
      tmp = x + y + z;
      x = y;
      y = z;
      z = tmp;
    }
    return z;
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N)$。

* 空间复杂度：$\mathcal{O}(1)$，保存最后 3 个斐波那契数。


#### 方法二：性能优化：带记忆的递归

- 预计算 38 个斐波那契数：

    - 初始化一个数组 `nums` 用于保存斐波那契数，并记录前 3 个斐波那契数。

    - 返回 `helper(n - 1)`。

- 递归方法 `helper(k)`：

    - 如果 `k == 0`，返回 0。
    
    - 如果 `nums[k] != 0`，返回 `nums[k]`。
    
    - 否则 `nums[k] = helper(k - 1) + helper(k - 2) + helper(k - 3)`，返回 `nums[k]`。

- 从预计算的数组中检索所需的斐波那契数。

```python [solution2-Python]
class Tri:
    def __init__(self):
        def helper(k):
            if k == 0:
                return 0
            
            if nums[k]:
                return nums[k]

            nums[k] = helper(k - 1) + helper(k - 2) + helper(k - 3) 
            return nums[k]
        
        n = 38
        self.nums = nums = [0] * n
        nums[1] = nums[2] = 1
        helper(n - 1)
                    
class Solution:
    t = Tri()
    def tribonacci(self, n: int) -> int:
        return self.t.nums[n]
```

```java [solution2-Java]
class Tri {
  private int n = 38;
  public int[] nums = new int[n];

  int helper(int k) {
    if (k == 0) return 0;
    if (nums[k] != 0) return nums[k];

    nums[k] = helper(k - 1) + helper(k - 2) + helper(k - 3);
    return nums[k];
  }

  Tri() {
    nums[1] = 1;
    nums[2] = 1;
    helper(n - 1);
  }
}

class Solution {
  public static Tri t = new Tri();
  public int tribonacci(int n) {
    return t.nums[n];
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(1)$，预计算 38 个斐波那契数，并在数组中检索。

* 空间复杂度：$\mathcal{O}(1)$，存储 38 个斐波那契数的数组。
 

#### 方法三：性能优化：动态计算

- 预计算 38 个斐波那契数：

    - 初始化一个数组用于保存斐波那契数，并初始化前 3 个斐波那契数字。

    - `i` 从 3 循环到 38，每一步计算出一个新的斐波那契数：`nums[i] = helper(i - 1) + helper(i - 2) + helper(i - 3)`。

- 从数组中检索所需的斐波那契数。

```python [solution3-Python]
class Tri:
    def __init__(self):
        n = 38
        self.nums = nums = [0] * n
        nums[1] = nums[2] = 1
        for i in range(3, n):
            nums[i] = nums[i - 1] + nums[i - 2] + nums[i - 3]
                    
class Solution:
    t = Tri()
    def tribonacci(self, n: int) -> int:
        return self.t.nums[n]
```

```java [solution3-Java]
class Tri {
  private int n = 38;
  public int[] nums = new int[n];
  Tri() {
    nums[1] = 1;
    nums[2] = 1;
    for (int i = 3; i < n; ++i)
      nums[i] = nums[i - 1] + nums[i - 2] + nums[i - 3];
  }
}

class Solution {
  public static Tri t = new Tri();
  public int tribonacci(int n) {
    return t.nums[n];
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(1)$，预计算 38 个斐波那契数字，并在数组中检索。

* 空间复杂度：$\mathcal{O}(1)$，存储 38 个斐波那契数字的数组。