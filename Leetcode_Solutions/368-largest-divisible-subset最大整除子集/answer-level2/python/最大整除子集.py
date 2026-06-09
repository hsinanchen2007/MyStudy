####  数学运算
在阐述解决方案之前，我们给出一些可以从模运算的性质中得到的推论，这些推论将在后面中用到。

给定升序序列（即 `E < F < G`）`[E, F, G]`，并且该列表本身满足问题中描述的整除子集，那么我们可以阔欧战该子集，而不必枚举该子集的所有数字，在以下两种情况：
- 推论一：可除以整除子集中的最大元素的任何值，加入到子集中，可以形成另一个整除子集，即对于所有 `h`，若有 `h % G == 0`，则 `[E, F, G, h]` 形成新的可除子集。
- 推论二：可除以整除子集中最小元素的任何值，加入到子集中，可以形成另一个整除子集，即，对于所有的 `d`，若有 `E % d == 0`，则 `[d, E, F, G]` 形成一个新的整除子集。

上面两个推论可以帮助我们构造一个有效的解决方案。

####  方法一：动态规划
这个问题似乎和哪些组合问题类似，比如 [两数之和](https://leetcode.com/problems/two-sum/)和 [三数之和](https://leetcode.com/problems/3sum/)。事实上，和这些组合问题一样，首先对原始列表进行排序是十分有帮助的，这样有助于减少末尾的枚举数。

对原始列表进行排序的另一个好处是，我们将能够应用本文开头解释的数学推论。

所以首先，我们对原始列表进行排序。事实证明，这是一个动态规划问题。解决动态规划的关键是用递归，合理的方法来表示问题。

对于有序列表 $[X_1，X_2。。。X_n]$ ，列表中的最大整除子集是以列表中每个数字结尾的所有可能的整除子集的最大子集。

让我们定义一个名为 $\text{EDS}(X_i)$ 的函数，它将给出以数字 $X_i$ 为结尾的最大整除子集。意味着 $X_i$ 是子集中最大的数字。例如，给定列表 $[2，4，7，8]$，让我们通过枚举计算 $\text{EDS}(4)$。首先，我们列出以 $4$ 结尾的所有整除子集，这些子集应该是 $\{4\}$ 和 $\{2，4\}$。根据定义，我们有 $\text{EDS}(4) = {2, 4}$，同样的，可以获得 $\text{EDS}(2) = {2}$ 和 $\text{EDS}(7) = {7}$。

注：一个数字本身也构成一个整除子集，尽管在问题的陈述中没有明确说明。

最后，我们定义目标函数，它将给出有序列表 $[X_1, X_2, ... X_n]$ 的最大整除子集为 $\text{LDS}([X_1, X_2, ... X_n])$。在没有进一步的说明清空下，下列的方程式成立：

$$\text{LDS}([X_1, X_2,...X_n]) = \max{ ( \forall \space \text{EDS}(X_i) )} \space, \space 1 \le i \le n   \quad \quad (1)$$

我们可以从定义上证明该公式。首先 $\forall \space \text{EDS}(X_i)$ 覆盖了所有情况下的整除子集（即子集以 $X_i$结尾）。然后在里面选出最大的子集。

此外，我们可以递归的计算函数 $\text{EDS}(X_i)$，并且使用开头的推论。

**算法：**

让我们解释以下如何计算 $\text{EDS}(X_i)$，下面的示例使用 $[2，4，7，8]$ 的列表。假设我们已经获得了小于 8 的所有元素的 $\text{EDS}(X_i)$ 的值，即：

$$\text{EDS}(2) = {2} \quad \text{EDS}(4) = {2, 4} \quad \text{EDS}(7) = {7}$$

要获取 $\text{EDS}(8)$，我们只需要分别枚举 $8$ 前面的所有元素及其 $\text{EDS}(X_i)$ 的值，步骤如下：

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMzY4LzM2OF9kcC5wbmc?x-oss-process=image/format,png)

- 如果数字 $8$ 可以被元素 $X_i$ 除，那么根据推论 1，通过将数字 $8$ 添加到 $\text{EDS}(X_i)$，我们获得另一个以 $8$ 结尾的整除子集。这个新子集代表了 $\text{EDS}(8)$ 的潜在值。例如，由于 $8 \bmod 2 == 0$，因此 $\{2，8\}$ 可以是 $\text{EDS}(8)$ 的最终值，与 $\text{EDS}(4)$ 获得的子集 $\{2，4，8\}$ 类似。
- 如果数字 $8$ 不能除以元素 $X_i$，那么根据整除子集的定义，我们可以确定 $\text{EDS}(X_i)$ 的值不会贡献给 $\text{EDS}(8)$。例如，子集 $\text{EDS}(7) = \{7\}$  对 $\text{EDS}(8)$ 没有影响。
- 然后，我们选择在 $\text{EDS}(X_i)$ 的帮助下形成最大的新子集。特别是子集 $\{8\}$ 代表 $\text{EDS}(8)$ 的有效候选项。如果假设 $8$ 不能被它前面的任何元素除，我么将得到 $\text{EDS}(8) = \{8\}$。

```python[solution1-Python]
class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # The container that holds all intermediate solutions.
        # key: the largest element in a valid subset.
        subsets = {-1: set()}
        
        for num in sorted(nums):
            subsets[num] = max([subsets[k] for k in subsets if num % k == 0], key=len) | {num}
        
        return list(max(subsets.values(), key=len))
```

```java[solution1-Java]
class Solution {
  public List<Integer> largestDivisibleSubset(int[] nums) {
    // Test case with empty set.
    int n = nums.length;
    if (n == 0) return new ArrayList();
        
    // Container to keep the largest divisible subset
    //   that ends with each of the nums.
    List<ArrayList> EDS = new ArrayList();
    for (int num : nums) EDS.add(new ArrayList());

    /* Sort the original list in ascending order. */
    Arrays.sort(nums);

    /* Calculate all the values of EDS(X_i) */
    for (int i = 0; i < n; ++i) {
      List<Integer> maxSubset = new ArrayList();
            
      // Find the largest divisible subset of previous elements.
      for (int k = 0; k < i; ++k) 
        if (nums[i] % nums[k] == 0 && maxSubset.size() < EDS.get(k).size())
          maxSubset = EDS.get(k);
          
      // Extend the found subset with the element itself.
      EDS.get(i).addAll(maxSubset);
      EDS.get(i).add(nums[i]);
    }
    /* Find the largest of EDS values  */
    List<Integer> ret = new ArrayList();
    for (int i = 0; i < n; ++i) 
      if (ret.size() < EDS.get(i).size()) ret = EDS.get(i);
    return ret;
  }  
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N^2)$。在算法的主循环中，我们需要为输入列表中的每个元素计算 $\text{EDS}(X_i)$。对于每个 $\text{EDS}(X_i)$ 的计算，我们需要枚举 $X_i$ 所有的元素。结果我们得到了 $\mathcal{O}(N^2)$  的时间复杂度。
* 空间复杂度：$\mathcal{O}(N^2)$，我们使用了一个容器来记录列表中每个元素 $\text{EDS}(X_i)$ 的值。在最坏的情况下，如果整个列表是一个整除子集，$\text{EDS}(X_i)$ 的值将是 $[X_1, X_2...X_i]$ 的子列表。结果我们得到了 $\mathcal{O}(N^2)$ 的空间复杂度。


####  方法二：使用更少空间的动态规划
遵循同样的动态规划直觉，我们可以在空间复杂度上做的更好。

我们不必为每个输入元素保留最大的整除子集，即 $\text{EDS}(X_i)$，而只需记录其大小，即 $\text{size}(\text{EDS}(X_i))$。因此，我们将空间复杂度从 $\mathcal{O}(N^2)$ 降到 $\mathcal{O}(N)$。

作为交换，我们需要在最后重建最大的整除子集，这是时间和空间之间的权衡。

**算法：**

主要算法与方法一几乎相同，该方法包括计算每个以 $X_i$ 结尾的最大整除子集大小。我们把这个结果向量表示为 `dp[i]`。

不同的是，我们需要一些额外的逻辑来从 `dp[i]` 中提取得到子集。在这里我们用下图所示的一个具体例子来阐述这个过程。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMzY4LzM2OF9kcF9sZXNzX3NwYWNlLnBuZw?x-oss-process=image/format,png)
在图的上部，我们有一个升序排列的元素列表（$X_i$），在图的下半部分，我们有最大整除子集的大小值，该子集以 $X_i$ 结尾。

为了便于阅读，我们在每个元素 $X_i$ 与其最大整除子集中的相邻元素之间绘制一个链接。例如，对于元素 $X_i = 8$，以 $8$ 为结尾的最大整除子集将是 $\{2, 4, 8\}$，并且我们看到 $8$ 与其邻居 $4$ 之间的链接。

结果子集的重建首先在 `dp[i]` 中找到最大的大小 （即 $4$）及其索引。由此得到的最大整除子集将以 `dp[i]` 的最大值元素结束。

然后从最大大小的索引开始，我们运行一个循环来向后（从 $X_i$ 到 $X_1$）查找应该包含在结果子集的下一个元素。

我们有两个标准来确定下一个元素：（1）元素应能够除以结果子集中的尾部元素，例如：$ 16 \bmod 8 == 0$。（2）`dp[i]` 的值应与整除子集的当前大小相对对应，例如，元素 7 不会是元素 8 的下一个相邻元素，因为他们的 `dp[i]` 值不匹配。

```python [solution2-Python]
class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if len(nums) == 0:
            return []

        # important step !
        nums.sort()
        
        # The container that keep the size of the largest divisible subset that ends with X_i
        # dp[i] corresponds to len(EDS(X_i))
        dp = [0] * (len(nums))
        
        """ Build the dynamic programming matrix/vector """
        for i, num in enumerate(nums):
            maxSubsetSize = 0
            for k in range(0, i):
                if nums[i] % nums[k] == 0:
                    maxSubsetSize = max(maxSubsetSize, dp[k])

            maxSubsetSize += 1
            dp[i] = maxSubsetSize
        
        """ Find both the size of largest divisible set and its index """ 
        maxSize, maxSizeIndex = max([(v, i) for i, v in enumerate(dp)])
        ret = []
        
        """ Reconstruct the largest divisible subset """ 
        # currSize: the size of the current subset
        # currTail: the last element in the current subset
        currSize, currTail = maxSize, nums[maxSizeIndex]
        for i in range(maxSizeIndex, -1, -1):
            if currSize == dp[i] and currTail % nums[i] == 0:
                ret.append(nums[i])
                currSize -= 1
                currTail = nums[i]
        
        return reversed(ret)
```

```java [solution2-Java]
class Solution {
  public List<Integer> largestDivisibleSubset(int[] nums) {
    // Test case with empty set.
    int n = nums.length;
    if (n == 0) return new ArrayList();
        
    // Container to keep the size of the largest divisible subset
    //   that ends with each of the nums.
    Integer[] dp = new Integer[n];

    /* Sort the original list in ascending order. */
    Arrays.sort(nums);

    Integer maxSubsetSize = -1, maxSubsetIndex = -1;
    
    /* Calculate the rest of EDS(X_i) */
    for (int i = 0; i < n; ++i) {
      Integer subsetSize = 0;

      // Find the size of the largest divisible subset.
      for (int k = 0; k < i; ++k) 
        if (nums[i] % nums[k] == 0 && subsetSize < dp[k])
          subsetSize = dp[k];

      // Extend the found subset with the element itself.
      dp[i] = subsetSize + 1;
    
      // We reuse this loop to obtain the largest subset size 
      //   in order to prepare for the reconstruction of subset.
      if (maxSubsetSize < dp[i]) {
        maxSubsetSize = dp[i];
        maxSubsetIndex = i;
      }
    }
    
    /* Reconstruct the largest divisible subset  */
    LinkedList<Integer> subset = new LinkedList();
    Integer currSize = maxSubsetSize;
    Integer currTail = nums[maxSubsetIndex];
    for (int i = maxSubsetIndex; i >= 0; --i) {
      if (currSize == 0) break;
    
      if (currTail % nums[i] == 0 && currSize == dp[i]) {
        subset.addFirst(nums[i]);
        currTail = nums[i];
        currSize -= 1;
      }
    }

    return subset;
  }  
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N^2)$。重建结果子集的附加逻辑需要额外的 $\mathcal{O}(N)$ 时间复杂度，这低于主循环需要的 $\mathcal{O}(N^2)$。
* 空间复杂度：$\mathcal{O}(N)$，向量 `dp[i]` 跟踪以每个元素结尾的最大整除子集的大小，在所有情况下都需要 $\mathcal{O}(N)$ 空间。


####  方法三：带记忆话的递归
动态规划的经典代码模式是维护一个中间解矩阵或向量，并且有一个或两个遍历矩阵或向量的循环。在循环过程中，我们重复使用中间结果，而不是每次都重新计算他们。

你们会注意到，上面的代码模式提醒我们使用记忆化的递归计数。实际上，有不止一种方法可以用动态规划的方法来实现解决方案。

**算法：**

在这里，我们强调了在这种情况下，将记忆和递归一起应用的重要性。

与方法一相同的示例，我们在下面绘制用于计算 $\text{EDS}(8)$ 的调用图，其中每个结点对应 $\text{EDS}(X_i)$ 函数的调用，并在边上指示调用顺序。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMzY4LzM2OF9yZWN1cnNpb25fbWVtb2l6YXRpb24ucG5n?x-oss-process=image/format,png)
我们可以看到，如果不保留中间结果，计算量将随着列表的长度呈指数增长。

```python [solution3-Python]
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        
        def EDS(i):
            """ recursion with memoization """
            if i in memo:
                return memo[i]
            
            tail = nums[i]
            maxSubset = []
            # The value of EDS(i) depends on it previous elements
            for p in range(0, i):
                if tail % nums[p] == 0:
                    subset = EDS(p)
                    if len(maxSubset) < len(subset):
                        maxSubset = subset
            
            # extend the found max subset with the current tail.
            maxSubset = maxSubset.copy()
            maxSubset.append(tail)
            
            # memorize the intermediate solutions for reuse.
            memo[i] = maxSubset
            return maxSubset
        
        # test case with empty set
        if len(nums) == 0: return []
        
        nums.sort()
        memo = {}
    
        # Find the largest divisible subset
        return max([EDS(i) for i in range(len(nums))], key=len)
```

```java [solution3-Java]
class Solution {
  HashMap<Integer, List<Integer>> _eds = new HashMap<Integer, List<Integer>>();
  int [] _nums = {};

  private List<Integer> EDS(Integer i) {
    // memoization
    if (this._eds.containsKey(i)) return this._eds.get(i);
      
    List<Integer> maxSubset = new ArrayList();
    // Find the largest divisible subset of previous elements.
    for (int k = 0; k < i; ++k) {
      if (this._nums[i] % this._nums[k] == 0) {
        List<Integer> subset = EDS(k);
        if (maxSubset.size() < subset.size()) maxSubset = subset;
      }    
    }
    // Extend the found subset with the element itself.
    List<Integer> newEntry = new ArrayList();
    newEntry.addAll(maxSubset);
    newEntry.add(this._nums[i]);

    // update the cached values
    this._eds.put(i, newEntry);
    return newEntry;
  }

  public List<Integer> largestDivisibleSubset(int[] nums) {
    // Test case with empty set.
    int n = nums.length;
    if (n == 0) return new ArrayList();
        
    // Container to keep the largest divisible subset
    //   that ends with each of the nums
    // key: the index of the element
    this._eds = new HashMap<Integer, List<Integer>>();
    
    /* Sort the original list in ascending order. */
    Arrays.sort(nums);
    this._nums = nums;
    
    List<Integer> maxSubset = new ArrayList();    
    /* Calculate the values of all EDS(X_i), 
       while keeping track of the largest one as the result value. */
    for (int i = 0; i < n; ++i) {
      List<Integer> subset = EDS(i);
      if (maxSubset.size() < subset.size()) maxSubset = subset;
    }
    
    // return the largest one
    return maxSubset;
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N^2)$，在上面的实现中，我们采用自下而上的策略，首先计算索引较低的元素的 $\text{EDS}(X_i)$。通过记忆化，后面 $\text{EDS}(X_i)$ 计算可以重用中间的计算。因此，我们达到与方法 1 相同的时间复杂度。
* 空间复杂度：$\mathcal{O}(N^2)$，在这个实现中，我们决定保留子集而不是其大小作为中间解决方案。正如我们在前面的方法中所讨论的，这将导致$\mathcal{O}(N^2)$ 空间复杂度，最坏的情况是整个输入列表是一个整除子集。此外，由于使用递归，在为有序列表中的最后一个元素调用 $\text{EDS}(X_n)$ 期间，程序将为调用堆栈产生最大的 $\mathcal{O}(N)$ 空间。不过，总体来说，空间复杂性仍然是 $\mathcal{O}(N^2)$。