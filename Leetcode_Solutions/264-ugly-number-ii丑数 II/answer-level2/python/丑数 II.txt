####  两级优化
假设我们以某种方式计算了第 `n` 个丑数，我们将这个解直接放到 `Solution` 类中的 `nthUglyNumber` 方法中。

让我们看一下上下文：有 596 个测试用例，其中大部分 n 是大于 50 小于 1691 的。

因此我们不必计算 $596 \times 50 = 29800$ 的丑数，而是可以预计算 1690 个丑数，这样可以显著的加快提交速度。

如何预计算？使用另一个 `Ugly` 类在构造函数中完成所有丑数的预计算，然后声明一个 `Ugly` 类的实例对象，将该实例对象声明为 `Solution` 类的静态变量。

现在让我们来讨论两种不同的预计算方法。

####  方法一：堆
我们从堆中包含一个数字开始：1，去计算下一个丑数。将 1 从堆中弹出然后将三个数字添加到堆中：$1 \times 2$, $1 \times 3$，和 $1 \times 5$。

现在堆中最小的数字是 2。为了计算下一个丑数，要将 2 从堆中弹出然后添加三个数字：$2 \times 2$, $2 \times 3$，和 $2 \times 5$。

重复该步骤计算所有丑数。在每个步骤中，弹出堆中最小的丑数 $k$，并在堆中添加三个丑数：$k \times 2$, $k \times 3$，和 $k \times 5$。

<![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjY0LzI2NF9zbF8xLnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjY0LzI2NF9zbF8yLnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjY0LzI2NF9zbF8zLnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjY0LzI2NF9zbF80LnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjY0LzI2NF9zbF81LnBuZw?x-oss-process=image/format,png)>

**算法：**
- 预计算 1690 个丑数：
	-  初始化预计算用到的数组 `nums`，堆 `heap` 和哈希表 `seen` 跟踪在堆中出现过的元素，避免重复。
	- 循环计算丑数，每个步骤：
		-  弹出堆中最小的数字 `k` 并添加到数组 `nums` 中。
		- 若 `2k`，`3k`，`5k` 不存在在哈希表中，则将其添加到栈中并更新哈希表。
- 返回在数组中预先计算好的丑数。

```python [solution1-Python]
from heapq import heappop, heappush
class Ugly:
    def __init__(self):
        seen = {1, }
        self.nums = nums = []
        heap = []
        heappush(heap, 1)

        for _ in range(1690):
            curr_ugly = heappop(heap)
            nums.append(curr_ugly)
            for i in [2, 3, 5]:
                new_ugly = curr_ugly * i
                if new_ugly not in seen:
                    seen.add(new_ugly)
                    heappush(heap, new_ugly)
    
class Solution:
    u = Ugly()
    def nthUglyNumber(self, n):
        return self.u.nums[n - 1]
```

```java [solution1-Java]
class Ugly {
  public int[] nums = new int[1690];
  Ugly() {
    HashSet<Long> seen = new HashSet();
    PriorityQueue<Long> heap = new PriorityQueue<Long>();
    seen.add(1L);
    heap.add(1L);

    long currUgly, newUgly;
    int[] primes = new int[]{2, 3, 5};
    for(int i = 0; i < 1690; ++i) {
      currUgly = heap.poll();
      nums[i] = (int)currUgly;
      for(int j : primes) {
        newUgly = currUgly * j;
        if (!seen.contains(newUgly)) {
          seen.add(newUgly);
          heap.add(newUgly);
        }
      }
    }
  }
}

class Solution {
  public static Ugly u = new Ugly();
  public int nthUglyNumber(int n) {
    return u.nums[n - 1];
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(1)$ 的时间检索答案。和超过 $12 \times 10^6$ 次预计算操作。我们估计一下预计算所需的操作次数。`For` 循环有 1690 步，且每一次循环执行一次 `pop` 操作和三次 `push` 操作和三次哈希表的 `contains / in` 操作。`pop` 和 `push` 操作具有对数时间复杂度因此比线性搜索更廉价，所以我们只估算 `contains / in` 带来的成本。该等差数列很容易估计：

$$1 + 2 + 3 + ... + 1690 \times 3 = \frac{(1 + 1690 \times 3) \times 1690 \times 3}{2} > 4.5 \times 1690^2$$

* 空间复杂度：常数空间存储 1690 个丑数，和堆中不超过 $1690 \times 2$ 的元素和哈希表中不超过 $1690 \times 3$ 的元素。



####  方法二： 动态规划
方法一中的预计算操作较为繁琐，可以通过动态规划优化。

让我们从数组中只包含一个丑数数字 1 开始，使用三个指针 $i_2$, $i_3$ 和 $i_5$，标记所指向丑数要乘以的因子。

算法很简单：在 $2 \times \textrm{nums}[i_2]$，$3 \times \textrm{nums}[i_3]$ 和 $5 \times \textrm{nums}[i_5]$ 选出最小的丑数并添加到数组中。并将该丑数对应的因子指针往前走一步。重复该步骤直到计算完 1690 个丑数。

<![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjY0LzI2NF9zbGlkZV8xLnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjY0LzI2NF9zbGlkZV8yLnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjY0LzI2NF9zbGlkZV8zLnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjY0LzI2NF9zbGlkZV80LnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjY0LzI2NF9zbGlkZV81LnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjY0LzI2NF9zbGlkZV82LnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjY0LzI2NF9zbGlkZV83LnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjY0LzI2NF9zbGlkZV84LnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjY0LzI2NF9zbGlkZV85LnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjY0LzI2NF9zbGlkZV8xMC5wbmc?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjY0LzI2NF9zbGlkZV8xMS5wbmc?x-oss-process=image/format,png)>

**算法：**
- 预计算 1690 个丑数：
	- 初始化数组 `nums` 和三个指针 `i2`，`i3`，`i5` 。
	- 循环计算所有丑数。每一步：
		- 在 `nums[i2] * 2`，`nums[i3] * 3` 和 `nums[i5] * 5` 选出最小的数字添加到数组 `nums` 中。
		- 将该数字对应的因子指针向前移动一步。
- 在数组中返回所需的丑数。 

```python [solution2-Python]
class Ugly:
    def __init__(self):
        self.nums = nums = [1, ]
        i2 = i3 = i5 = 0

        for i in range(1, 1690):
            ugly = min(nums[i2] * 2, nums[i3] * 3, nums[i5] * 5)
            nums.append(ugly)

            if ugly == nums[i2] * 2: 
                i2 += 1
            if ugly == nums[i3] * 3:
                i3 += 1
            if ugly == nums[i5] * 5:
                i5 += 1
            
class Solution:
    u = Ugly()
    def nthUglyNumber(self, n):
        return self.u.nums[n - 1]
```

```java [solution2-Java]
class Ugly {
  public int[] nums = new int[1690];
  Ugly() {
    nums[0] = 1;
    int ugly, i2 = 0, i3 = 0, i5 = 0;

    for(int i = 1; i < 1690; ++i) {
      ugly = Math.min(Math.min(nums[i2] * 2, nums[i3] * 3), nums[i5] * 5);
      nums[i] = ugly;

      if (ugly == nums[i2] * 2) ++i2;
      if (ugly == nums[i3] * 3) ++i3;
      if (ugly == nums[i5] * 5) ++i5;
    }
  }
}

class Solution {
  public static Ugly u = new Ugly();
  public int nthUglyNumber(int n) {
    return u.nums[n - 1];
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(1)$ 时间检索答案和大约 $1690 \times 5 = 8450$ 次的预计算操作。
* 空间复杂度：常数空间用保存 1690 个丑数。