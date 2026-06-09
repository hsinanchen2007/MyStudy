####  概述
这个问题的衍生问题是解决任意长度 $L$  的相同问题。在这里我们将 $L=10$ 来简化问题。

我们将讨论三种不同的方法，它们都是基于滑动窗口和 `hashset` 的，关键是如何实现一个窗口切片。

在线性时间 $\mathcal{O}(L)$ 内获取窗口切片很简单也比较笨。

总的来说，这样回导致 $\mathcal{O}((N - L) L)$ 的时间消耗和巨大的空间小寒。常数时间的窗口切片 $\mathcal{O}(1)$ 是一个好的方法，根据实现方式可以分为两种方法：
- Rabin-Karp 算法 = 使用旋转哈希算法实现常数窗口切片。
- 位操作 = 使用掩码实现常数窗口切片。

后面的两种方法具有 $\mathcal{O}(N - L)$ 的时间复杂度和适度的空间消耗，即使在长度很长的序列也是如此。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMTg3L2FsZ29yaXRobXMucG5n?x-oss-process=image/format,png)

####  方法一：线性时间窗口切片 + HashSet
**算法：**
- 沿长度为 $N$ 的字符串移动长度为 $L$ 的滑动窗口。
- 检查滑动窗口中的序列是否在 Hashset `seen` 中。
	- 如果是，则找到了重复的序列。更新输出。
	- 否则，将序列添加到 HashSet `seen` 中。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMTg3L2hhc2hlczIucG5n?x-oss-process=image/format,png)

```python [solution1-Python]
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        L, n = 10, len(s)     
        seen, output = set(), set()

        # iterate over all sequences of length L
        for start in range(n - L + 1):
            tmp = s[start:start + L]
            if tmp in seen:
                output.add(tmp[:])
            seen.add(tmp)
        return output
```

```java [solution1-Java]
class Solution {
  public List<String> findRepeatedDnaSequences(String s) {
    int L = 10, n = s.length();
    HashSet<String> seen = new HashSet(), output = new HashSet();

    // iterate over all sequences of length L
    for (int start = 0; start < n - L + 1; ++start) {
      String tmp = s.substring(start, start + L);
      if (seen.contains(tmp)) output.add(tmp);
      seen.add(tmp);
    }
    return new ArrayList<String>(output);
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}((N - L)L)$。在执行的循环中，有 $N-L+1$ 个长度为 $L$ 的子字符串，这会导致 $\mathcal{O}((N - L)L)$ 时间复杂性。
* 空间复杂度：使用了 $\mathcal{O}((N - L)L)$ 去存储 HashSet，由于 $L=10$ 最终为时间复杂度为 $\mathcal{O}(N)$。


####  方法二：Rabin-Karp：使用旋转哈希实现常数时间窗口切片
Rabin-Karp 算法用于多模式搜索，常用于重复检测和生物信息学中寻找两个或多个蛋白质的相似性。

在文章[最长的重复子串](https://leetcode.com/articles/longest-duplicate-substring/)中详细实现了 Rabin-Karp 算法，在这里我们做一个基本的实现。

其思想是对字符串进行切片并在滑动窗口中计算序列的哈希值，两者都是在一个常数的时间内进行的。

让我们使用 `AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT` 作为例子。首先，将字符串转换为整数数组。

- 'A' -> 0, 'C' -> 1, 'G' -> 2, 'T' -> 3

`AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT` -> `00000111110000011111100000222333`。计算第一个序列的哈希值:`0000011111`。在基数为 4 的数字系统中，该序列可视为一个数字，并散列为：

$h_0 = \sum_{i = 0}^{L - 1}{c_i 4^{L - 1 - i}}$

$c_{0..4} = 0$ 和 $c_{5..9} = 1$ 代表了 `0000011111`。

现在我们考虑切片 `AAAAACCCCC` -> `AAAACCCCCA`。 在整数数组中表示 `0000011111` -> `0000111110`，若要删除前导 0 并添加末尾 0，则重新计算哈希：

$h_1 = (h_0 \times 4 - c_0 4^L) + c_{L + 1}$。

可以发现窗口切片和计算散列都是在常数时间内完成的。

**算法：**

- 从序列初始位置遍历序列：从 `1` 到 `N-1`。
	- 如果 `start==0`，计算第一个序列 `s[0:L]` 的哈希值。
	- 否则，从上一个哈希值计算旋转哈希。
	- 如果哈希值在 hashset 中，则找到了重复的序列，则更新输出。
	- 否则，添加到将哈希值添加到 hashset 中。
- 返回输出列表。

```python [solution2-Python]
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        L, n = 10, len(s)
        if n <= L:
            return []
        
        # rolling hash parameters: base a
        a = 4
        aL = pow(a, L) 
        
        # convert string to array of integers
        to_int = {'A': 0, 'C': 1, 'G': 2, 'T': 3}
        nums = [to_int.get(s[i]) for i in range(n)]
        
        h = 0
        seen, output = set(), set()
        # iterate over all sequences of length L
        for start in range(n - L + 1):
            # compute hash of the current sequence in O(1) time
            if start != 0:
                h = h * a - nums[start - 1] * aL + nums[start + L - 1]
            # compute hash of the first sequence in O(L) time
            else:
                for i in range(L):
                    h = h * a + nums[i]
            # update output and hashset of seen sequences
            if h in seen:
                output.add(s[start:start + L])
            seen.add(h)
        return output
```

```java [solution2-Java]
class Solution {
  public List<String> findRepeatedDnaSequences(String s) {
    int L = 10, n = s.length();
    if (n <= L) return new ArrayList();

    // rolling hash parameters: base a
    int a = 4, aL = (int)Math.pow(a, L);

    // convert string to array of integers
    Map<Character, Integer> toInt = new
            HashMap() {{put('A', 0); put('C', 1); put('G', 2); put('T', 3); }};
    int[] nums = new int[n];
    for(int i = 0; i < n; ++i) nums[i] = toInt.get(s.charAt(i));

    int h = 0;
    Set<Integer> seen = new HashSet();
    Set<String> output = new HashSet();
    // iterate over all sequences of length L
    for (int start = 0; start < n - L + 1; ++start) {
      // compute hash of the current sequence in O(1) time
      if (start != 0)
        h = h * a - nums[start - 1] * aL + nums[start + L - 1];
      // compute hash of the first sequence in O(L) time
      else
        for(int i = 0; i < L; ++i) h = h * a + nums[i];
      // update output and hashset of seen sequences
      if (seen.contains(h)) output.add(s.substring(start, start + L));
      seen.add(h);
    }
    return new ArrayList<String>(output);
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N - L)$。
* 空间复杂度：使用了 $\mathcal{O}(N - L)$ 存储 hashset，因为 $L=10$，最终为 $\mathcal{O}(N)$。


####  方法三：位操作：使用掩码实现常数时间窗口切片
其思想是对字符串进行切片，并在滑动窗口中计算序列的掩码，两者都是在一个恒定的时间内进行的。

和 Rabin-Karp 一样，将字符串转换为两个比特位整数数组。

$A -> 0 = 00_2, \quad C -> 1 = 01_2, \quad G -> 2 = 10_2, \quad T -> 3 = 11_2$。

`GAAAAACCCCCAAAAACCCCCCAAAAAGGGTTT` -> `200000111110000011111100000222333`。

计算第一个序列的掩码：`200000111`。序列中的每个数字（0、1、2 或 3）占用的位不超过2位：

$0 = 00_2, \quad 1 = 01_2, \quad 2 = 10_2, \quad 3 = 11_2$

因此，可以在循环中计算掩码：
- 左移以释放最后两位：`bitmask <<= 2`。
- 将当前数字存储到 `2000001111` 的后两位：`bitmask |= nums[i]`。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMTg3L2ZpcnN0X2JpdG1hc2syLnBuZw?x-oss-process=image/format,png)

现在我们考虑切片：`GAAAAACCCCC` -> `AAAAACCCCC`。在整形数组中表示 `20000011111` -> `0000011111`，删除前导 2 并添加末尾 1。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMTg3L3NsaWNlLnBuZw?x-oss-process=image/format,png)
添加末尾 1 很简单，和上面的思路一样：
- 左移以释放最后两位：`bitmask <<= 2`。
- 添加 1  到最后两位：`bitmask |= 1`。

现在的问题是删除前导 2。换句话说，问题是将 2L 位和 (2L + 1) 位设置为零。

我们可以使用一个技巧去重置第 n 位的值：`bitmask &= ~(1 << n)`。

这个技巧很简单：
- `1 << n` 是设置第 n 位为 1。
- `~(1 << n)` 是设置第 n 位为 0，且全部低位为 1。
- `bitmask &= ~(1 << n)` 是将 bitmask 第 n 位设置为 0。

技巧的简单使用方法是先设置第 2L 位，然后再设置 (2L + 1) 位：`bitmask &= ~(1 << 2 * L) & ~(1 << (2 * L + 1)`。可以简化为 `bitmask &= ~(3 << 2 * L)`：
- $3 = (11)_2$，因此可以设置第 2L 位和第 (2L + 1) 位为 1。
- `~(3 << 2 * L)` 会设置第 2L 位 和第 (2L + 1) 位为 0，且所有低位为 1。
- `bitmask &= ~(3 << 2 * L)` 则会将 bitmask 第 2L 和第 (2L + 1) 位设置为 0。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMTg3L3Vuc2V0LnBuZw?x-oss-process=image/format,png)
可以看到窗口切片和掩码都是在一个常数时间内完成的。

**算法：**
- 遍历序列的起始位置：从 1 到 $N - L$。
	- 如果 `start == 0`，计算第一个序列 `s[0:L]` 的掩码。
	- 否则，从前一个掩码计算当前掩码。
	- 如果掩码在 hashset 中，说明是重复序列，更新输出。
	- 否则，将该掩码添加到 hashset。
- 返回输出列表。  

```python [solution3-Python]
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        L, n = 10, len(s)
        if n <= L:
            return []
        
        # convert string to the array of 2-bits integers:
        # 00_2, 01_2, 10_2 or 11_2
        to_int = {'A': 0, 'C': 1, 'G': 2, 'T': 3}
        nums = [to_int.get(s[i]) for i in range(n)]
        
        bitmask = 0
        seen, output = set(), set()
        # iterate over all sequences of length L
        for start in range(n - L + 1):
            # compute bitmask of the sequence in O(1) time
            if start != 0:
                # left shift to free the last 2 bit
                bitmask <<= 2
                # add a new 2-bits number in the last two bits
                bitmask |= nums[start + L - 1]
                # unset first two bits: 2L-bit and (2L + 1)-bit
                bitmask &= ~(3 << 2 * L)
            # compute bitmask of the first sequence in O(L) time
            else:
                for i in range(L):
                    bitmask <<= 2
                    bitmask |= nums[i]
            if bitmask in seen:
                output.add(s[start:start + L])
            seen.add(bitmask)
        return output
```

```java [solution3-Java]
class Solution {
  public List<String> findRepeatedDnaSequences(String s) {
    int L = 10, n = s.length();
    if (n <= L) return new ArrayList();

    // rolling hash parameters: base a
    int a = 4, aL = (int)Math.pow(a, L);

    // convert string to array of integers
    Map<Character, Integer> toInt = new
            HashMap() {{put('A', 0); put('C', 1); put('G', 2); put('T', 3); }};
    int[] nums = new int[n];
    for(int i = 0; i < n; ++i) nums[i] = toInt.get(s.charAt(i));

    int bitmask = 0;
    Set<Integer> seen = new HashSet();
    Set<String> output = new HashSet();
    // iterate over all sequences of length L
    for (int start = 0; start < n - L + 1; ++start) {
      // compute bitmask of the current sequence in O(1) time
      if (start != 0) {
        // left shift to free the last 2 bit
        bitmask <<= 2;
        // add a new 2-bits number in the last two bits
        bitmask |= nums[start + L - 1];
        // unset first two bits: 2L-bit and (2L + 1)-bit
        bitmask &= ~(3 << 2 * L);
      }
      // compute hash of the first sequence in O(L) time
      else {
        for(int i = 0; i < L; ++i) {
          bitmask <<= 2;
          bitmask |= nums[i];
        }
      }
      // update output and hashset of seen sequences
      if (seen.contains(bitmask)) output.add(s.substring(start, start + L));
      seen.add(bitmask);
    }
    return new ArrayList<String>(output);
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N - L)$。
* 空间复杂度：使用了 $\mathcal{O}(N - L)$ 存储 hashset，因为 $L=10$，最终为 $\mathcal{O}(N)$。