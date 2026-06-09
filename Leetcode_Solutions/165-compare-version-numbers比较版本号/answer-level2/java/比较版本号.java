####  方法一：分割+解析，两次遍历，线性空间
第一个想法是将两个字符串按点字符分割成块，然后逐个比较这些块。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMTY1L3lveW8zLnBuZw?x-oss-process=image/format,png)
如果两个版本号的块数相同，则可以有效工作。如果不同，则需要在较短字符串末尾补充相应的 `.0` 块数使得块数相同。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMTY1L2RpZmYzLnBuZw?x-oss-process=image/format,png)

**算法：**
- 根据点分割两个字符串将分割的结果存储到数组中。
- 遍历较长数组并逐个比较块。如果其中一个数组结束了，实际上可以根据需要添加尽可能多的零，以继续与较长的数组进行比较。
	-  如果两个版本号不同，则返回 1 或 -1。
- 版本号相同，返回 0。 

```python [solution1-Python]
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        nums1 = version1.split('.')
        nums2 = version2.split('.')
        n1, n2 = len(nums1), len(nums2)
        
        # compare versions
        for i in range(max(n1, n2)):
            i1 = int(nums1[i]) if i < n1 else 0
            i2 = int(nums2[i]) if i < n2 else 0
            if i1 != i2:
                return 1 if i1 > i2 else -1
        
        # the versions are equal
        return 0 
```

```java [solution1-Java]
class Solution {
  public int compareVersion(String version1, String version2) {
    String[] nums1 = version1.split("\\.");
    String[] nums2 = version2.split("\\.");
    int n1 = nums1.length, n2 = nums2.length;

    // compare versions
    int i1, i2;
    for (int i = 0; i < Math.max(n1, n2); ++i) {
      i1 = i < n1 ? Integer.parseInt(nums1[i]) : 0;
      i2 = i < n2 ? Integer.parseInt(nums2[i]) : 0;
      if (i1 != i2) {
        return i1 > i2 ? 1 : -1;
      }
    }
    // the versions are equal
    return 0;
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N + M + \max(N, M))$。其中 $N$ 和 $M$ 指的是输入字符串的长度。 
* 空间复杂度：$\mathcal{O}(N + M)$，使用了两个数组 `nums1` 和 `nums2` 存储两个字符串的块。


####  方法二：双指针，一次遍历，常数空间
方法一有两个缺点：
- 是两次遍历的解决方法。
- 消耗线性空间。

我们能否实现一个只有一次遍历和消耗常数空间的解决方法呢？

其思想是在每个字符串上使用两个指针，跟踪每个数组的开始和结束。

这样，可以并行地沿着两个字符串移动，检索并比较相应的块。一旦两个字符串都被解析，比较也就完成了。

**算法：**

首先，我们定义了一个名为 `get_next_chunk(version, n, p)` 的函数，用于检索字符串中的下一个块。这个函数有三个参数：输入字符串 `version`，它的长度 `n`，以及指针 `p` 为要检索块的第一个字符。它在指针 `p` 和下一个点之间返回一个整数块。为了帮助迭代，返回的是下一个快的第一个字符的指针。下面是如何使用此函数解决问题的方法：

- 指针 `p1` 和 `p2` 分别指向 `version1` 和 `version2` 的起始位置：`p1=p2=0`。
- 并行遍历两个字符串。当 `p1 < n1 or p2 < n2`：
	- 使用 `get_next_chunk` 函数获取 `version1` 和 `version2` 的下一个块 `i1` 和 `i2`。
	- 比较 `i1` 和 `i2`。如果不相同，则返回 1 或 -1。
- 如果到了这里，说明版本号相同，则返回 0。

下面实现 `get_next_chunk(version, n, p)` 函数：
- 块的开头由指针 `p` 标记。如果 `p` 设置为字符串的结尾，则字符串解析完成。若要继续比较，则在添加 `.0` 返回。
- 如果 `p` 不在字符串的末尾，则沿字符串移动指针 `p_end` 以查找块的结尾。
- 返回块 `version.substring(p, p_end)`。

<![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMTY1LzE2NV9zbF8xLnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMTY1LzE2NV9zbF8yLnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMTY1LzE2NV9zbF8zLnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMTY1LzE2NV9zbF80LnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMTY1LzE2NV9zbF81LnBuZw?x-oss-process=image/format,png)>

```python [solution2-Python]
class Solution:
    def get_next_chunk(self, version: str, n: int, p: int) -> List[int]:
        # if pointer is set to the end of string
        # return 0
        if p > n - 1:
            return 0, p
        
        # find the end of chunk
        p_end = p
        while p_end < n and version[p_end] != '.':
            p_end += 1
        # retrieve the chunk
        i = int(version[p:p_end]) if p_end != n - 1 else int(version[p:n])
        # find the beginning of next chunk
        p = p_end + 1
        
        return i, p
        
    def compareVersion(self, version1: str, version2: str) -> int:
        p1 = p2 = 0
        n1, n2 = len(version1), len(version2)
        
        # compare versions
        while p1 < n1 or p2 < n2:
            i1, p1 = self.get_next_chunk(version1, n1, p1)
            i2, p2 = self.get_next_chunk(version2, n2, p2)            
            if i1 != i2:
                return 1 if i1 > i2 else -1
        
        # the versions are equal
        return 0    
```

```java [solution2-Java]
class Solution {
  public Pair<Integer, Integer> getNextChunk(String version, int n, int p) {
    // if pointer is set to the end of string
    // return 0
    if (p > n - 1) {
      return new Pair(0, p);
    }
    // find the end of chunk
    int i, pEnd = p;
    while (pEnd < n && version.charAt(pEnd) != '.') {
      ++pEnd;
    }
    // retrieve the chunk
    if (pEnd != n - 1) {
      i = Integer.parseInt(version.substring(p, pEnd));
    } else {
      i = Integer.parseInt(version.substring(p, n));
    }
    // find the beginning of next chunk
    p = pEnd + 1;

    return new Pair(i, p);
  }

  public int compareVersion(String version1, String version2) {
    int p1 = 0, p2 = 0;
    int n1 = version1.length(), n2 = version2.length();

    // compare versions
    int i1, i2;
    Pair<Integer, Integer> pair;
    while (p1 < n1 || p2 < n2) {
      pair = getNextChunk(version1, n1, p1);
      i1 = pair.getKey();
      p1 = pair.getValue();

      pair = getNextChunk(version2, n2, p2);
      i2 = pair.getKey();
      p2 = pair.getValue();
      if (i1 != i2) {
        return i1 > i2 ? 1 : -1;
      }
    }
    // the versions are equal
    return 0;
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(\max(N, M))$。其中 $N$ 和 $M$ 指的是输入字符串的长度。
* 空间复杂度：$\mathcal{O}(1)$，没有使用额外的数据结构。