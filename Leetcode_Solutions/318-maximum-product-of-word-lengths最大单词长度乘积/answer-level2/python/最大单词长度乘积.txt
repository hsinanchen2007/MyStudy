#### 综述

从简单方法开始慢慢深入。

> 将每个单词与其他所有单词一一比较。如果两个单词没有公共字母，则更新 `maxProd`。


先不考虑实现方法 `noCommonLetters`，该解法的代码如下：

```python [snippet1-Python]
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        def no_common_letters(s1, s2):
            # TODO
            
        n = len(words)
        max_prod = 0
        for i in range(n):
            for j in range(i + 1, n):
                if no_common_letters(words[i], words[j]):
                    max_prod = max(max_prod, len(words[i]) * len(words[j]))
        return max_prod
```

```java [snippet1-Java]
class Solution {
  public boolean noCommonLetters(String s1, String s2){
    // TODO
  }

  public int maxProduct(String[] words) {
    int n = words.length;

    int maxProd = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        if (noCommonLetters(words[i], words[j]))
          maxProd = Math.max(maxProd, words[i].length() * words[j].length());

    return maxProd;
  }
}
```

嵌套循环执行的次数为：
 
$(N - 1) + (N - 2) + ... + 2 + 1 = \frac{N(N - 1)}{2}$

达到 $\mathcal{O}(N^2 \times f(L_1, L_2))$ 的时间复杂度。其中 $f(L_1, L_2)$ 是方法 `noCommonLetters(String s1, String s2)` 的时间复杂度，代表比较两个长度为 $L_1$ 和 $L_2$ 的字符串。

> 接下来怎么做？

![](https://pic.leetcode-cn.com/Figures/318/methods2.png){:width=500}

- 方法一：最小化方法 $f(L_1, L_2)$ 的复杂度。

- 方法二：最小化单词的比较次数。不需要 $\mathcal{O}(N^2)$ 次比较，在所有具有相同字符集的单词中只保留最长的一个单词。例：（$ab$，$aaaaabaabaaabb$，$bbabbabba$）中只保留最长的一个单词（$aaaaabaabaaabb$）。


#### 方法一：优化的方法 noCommonLetters：位操作+预计算

首先最小化单词比较 $f(L_1, L_2)$ 的复杂度。

![](https://pic.leetcode-cn.com/Figures/318/methods.png){:width=500}

**简单解法：$\mathcal{O}(L_1 \times L_2)$**

逐个检查第一个单词的每个字母是否出现在第二个单词中，这种方法不是最优的。

```python [snippet2-Python]
def no_common_letters(s1, s2):
    for ch in s1:
        if ch in s2:
            return False
    return True
```

```java [snippet2-Java]
public boolean noCommonLetters(String s1, String s2){
  for (char ch : s1.toCharArray())
    if (s2.indexOf(ch) != -1) return false;
  return true;
}
```
 
**位操作：$\mathcal{O}(L_1 + L_2)$**

更好的方法是使用位操作。

单词仅包含小写字母，可以使用 26 个字母的位掩码对单词的每个字母处理，判断是否存在某个字母。如果单词中存在字母 `a`，则将位掩码的第一位设为 `1`，否则设为 `0`。如果单词中存在字母 `b`，则将位掩码的第二位设为 `1`，否则设为 `0`。依次类推，一直判断到字母 `z`。

![](https://pic.leetcode-cn.com/Figures/318/n_th.png){:width=500}

> 如何设置掩码的第 n 位？使用标准的位操作：`n_th_bit = 1 << n`。

> 如何计算一个单词的位掩码？遍历单词的每个字母，计算该字母在掩码中的位置 `n = (int)ch - (int)'a'`，然后创建一个第 n 位为 1 的掩码 `n_th_bit = 1 << n`，通过或操作将该码合并到位掩码中 `bitmask |= n_th_bit`。

![](https://pic.leetcode-cn.com/Figures/318/bitmask.png){:width=500}

该方法对每个字母计算一次掩码，花费时间 $\mathcal{O}(L_1 + L_2)$。单词比较可以在恒定时间内完成。


```python [snippet3-Python]
def no_common_letters(s1, s2):
    bit_number = lambda ch : ord(ch) - ord('a')

    bitmask1 = bitmask2 = 0
    for ch in s1:
        bitmask1 |= 1 << bit_number(ch)
    for ch in s2:
        bitmask2 |= 1 << bit_number(ch)
    return bitmask1 & bitmask2 == 0
```

```java [snippet3-Java]
public int bitNumber(char ch) {
  return (int)ch - (int)'a';
}

public boolean noCommonLetters(String s1, String s2) {
  int bitmask1 = 0, bitmask2 = 0;
  for (char ch : s1.toCharArray())
    bitmask1 |= 1 << bitNumber(ch);
  for (char ch : s2.toCharArray())
    bitmask2 |= 1 << bitNumber(ch);

  return (bitmask1 & bitmask2) == 0;
}
```

**位掩码+预计算：使用 $\mathcal{O}(1)$ 的时间比较**

前面方法中，每个单词需要计算 N 次位掩码。实际上，每个单词的位掩码可以预先计算并存储起来，之后每次直接拿来比较。

因为 Java 的优化，操作数组比 HashMap 更快，所以使用两个整数数组存储位掩码和字符串长度。

**算法**

- 预计算所有单词的位掩码，并把它们存储在数组 `masks` 中。使用数组 `lens` 存储所有单词的长度。

- 逐一两两比较单词。如果两个单词不存在公共字母，则更新最大单词长度乘积 `maxProd`。使用数组 `masks` 可以在常数时间内判断两个单词是否包含公共字母：`(masks[i] & masks[j]) == 0`。

- 返回 `maxProd`。

```python [solution1-Python]
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        n = len(words)
        masks = [0] * n
        lens = [0] * n
        bit_number = lambda ch : ord(ch) - ord('a')
        
        for i in range(n):
            bitmask = 0
            for ch in words[i]:
                # add bit number bit_number in bitmask
                bitmask |= 1 << bit_number(ch)
            masks[i] = bitmask
            lens[i] = len(words[i])
            
        max_val = 0
        for i in range(n):
            for j in range(i + 1, n):
                if masks[i] & masks[j] == 0:
                    max_val = max(max_val, lens[i] * lens[j])
        return max_val
```

```java [solution1-Java]
class Solution {
  public int bitNumber(char ch) {
    return (int)ch - (int)'a';
  }

  public int maxProduct(String[] words) {
    int n = words.length;
    int[] masks = new int[n];
    int[] lens = new int[n];

    int bitmask = 0;
    for (int i = 0; i < n; ++i) {
      bitmask = 0;
      for (char ch : words[i].toCharArray()) {
        // add bit number bit_number in bitmask
        bitmask |= 1 << bitNumber(ch);
      }
      masks[i] = bitmask;
      lens[i] = words[i].length();
    }

    int maxVal = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        if ((masks[i] & masks[j]) == 0)
          maxVal = Math.max(maxVal, lens[i] * lens[j]);

    return maxVal;
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N^2 + L)$，其中 $N$ 是单词数量，$L$ 是所有单词的总长度。预计算处理所有单词的所有字母的复杂度为 $\mathcal{O}(L)$。单词两两比较的复杂度为 $\mathcal{O}(N^2)$。总复杂度为 $\mathcal{O}(N^2 + L)$。

* 空间复杂度：$\mathcal{O}(N)$，存储 $N$ 个元素的两个数组。


#### 方法二：优化比较次数：位操作+预计算+HashMap

方法一优化了比较过程，方法二优化比较次数。完成所有的两两比较需要 $\mathcal{O}(N^2)$。一些单词具有相同的字符集，则只保留这些单词中最长的一个单词即可。例如：单词集合（$ab$，$aaaaabaabaaabb$，$bbabbabba$）只保留单词 $aaaaabaabaaabb$ 即可。使用 HashMap 代替方法一中的两个长度为 $N$ 的数组，存储结构为：位掩码 -> 该掩码对应的最大长度字符串。

![](https://pic.leetcode-cn.com/Figures/318/same.png){:width=500}

这种方法单词比较次数可能会减少，从而提高 Python 解法的效率。由于 Java 中 HashMap 的性能问题，这种方法不会改善 Java 解法的效率。

**算法**

- 预计算所有单词的位掩码，并将它们存储在 HashMap 中：位掩码 -> 该掩码对应的最大长度字符串。例如：单词 “aaaaaaa” 和 “a” 具有相同的掩码。 

- 逐一两两比较 HashMap 中的单词。如果两个单词没有公共字母，更新最大单词长度乘积 `maxProd`。使用位掩码可以在常数时间内判断两个单词是否包含公共字母：`(x & y) == 0`。

- 返回 `maxProd`。

```python [solution2-Python]
from collections import defaultdict
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        hashmap = defaultdict(int)
        bit_number = lambda ch : ord(ch) - ord('a')
        
        for word in words:
            bitmask = 0
            for ch in word:
                # add bit number bit_number in bitmask
                bitmask |= 1 << bit_number(ch)
            # there could be different words with the same bitmask
            # ex. ab and aabb
            hashmap[bitmask] = max(hashmap[bitmask], len(word))
        
        max_prod = 0
        for x in hashmap:
            for y in hashmap:
                if x & y == 0:
                    max_prod = max(max_prod, hashmap[x] * hashmap[y])
        return max_prod
```

```java [solution2-Java]
class Solution {
  public int bitNumber(char ch){
    return (int)ch - (int)'a';
  }

  public int maxProduct(String[] words) {
    Map<Integer, Integer> hashmap = new HashMap();

    int bitmask = 0, bitNum = 0;
    for (String word : words) {
      bitmask = 0;
      for (char ch : word.toCharArray()) {
        // add bit number bitNumber in bitmask
        bitmask |= 1 << bitNumber(ch);
      }
      // there could be different words with the same bitmask
      // ex. ab and aabb
      hashmap.put(bitmask, Math.max(hashmap.getOrDefault(bitmask, 0), word.length()));
    }

    int maxProd = 0;
    for (int x : hashmap.keySet())
      for (int y : hashmap.keySet())
        if ((x & y) == 0) maxProd = Math.max(maxProd, hashmap.get(x) * hashmap.get(y));

    return maxProd;
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N^2 + L)$，其中 $N$ 是单词数量，$L$ 是所有单词的所有字母的数量。当 $N > 2^{26}$ 时，时间复杂度为 $\mathcal{O}(L)$。

* 空间复杂度：$\mathcal{O}(N)$，使用一个长度为 $N$ 的 HashMap。