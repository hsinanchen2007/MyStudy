####  方法一：带记忆的递归
这里的第一个想法是递归，是一个较为简单的方法，但是如果输入的字符串过长会导致递归深度很大，因此比较耗时。

- 如果字符串相等 `p == s`，返回 `True`。
- 如果 `p == '*'`，返回 `True`。
- 如果 `p` 为空或 `s` 为空，返回 `False`。
- 若当前字符匹配，即 `p[0] == s[0]` 或 `p[0] == '?'`，然后比较下一个字符，返回 `isMatch(s[1:], p[1:])`。
- 如果当前的字符模式是一个星号 `p[0] == '*'`，则有两种情况。
	- 星号没有匹配字符，因此答案是 `isMatch(s, p[1:])`。
	- 星号匹配一个字符或更多字符，因此答案是 `isMatch(s[1:], p)`。
	- 若 `p[0] != s[0]`，返回 `False`。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDQvc3R1cGlkLnBuZw?x-oss-process=image/format,png)
这个算法由于时间限制，他没有通过所有的测试用例，因此必须进行优化，以下是可以做到的：
1. 记忆。这是优化递归的标准方法。我们使用 `(s, p)` 作为键，使用匹配与不匹配作为布尔值。创建一个记忆的哈希映射。将所有已经检查的 `(s, p)` 保留在哈希映射中。这样，如果有任何重复的检查，只需查看哈希表，而不需再次进行计算。
2. 清理输入数据，不管 `a****bc**cc` 中有多少个星号，它们都可以简化为 `a*bc*cc`。这样的清理有助于减少递归深度。

**算法：**

- 清理输入数据用一个星号代替多个星号：`p = remove_duplicate_stars(p)`。
- 初始化记忆哈希表 `dp`。
- 返回 `helper` 函数，用清理后的输入作为参数。
- `helper(s,p)`：
	-  如果 `(s,p)` 已经计算过存储在 `dp` 中，则返回 `dp` 中的值。
	- 如果字符串相等 `p == s` 或 `p == '*'`，在 `dp` 添加 `dp[(s, p)] = True`。
	- 反之如果 `p` 或 `s` 为空，则 `dp[(s, p)] = False`。
	- 反之如果当前字符匹配，即 `p[0] == s[0]` 或 `p[0] == '?'`，则继续检查下一个字符并 `dp[(s, p)] = helper(s[1:], p[1:])`。
	- 反之如果当前字符模式是一个星号 `p[0] == '*'`，则有两种情况，要么不匹配字符要么匹配一个或多个，符，则 `dp[(s, p)] = helper(s, p[1:]) or helper(s, p[1:])`。
	- 反之如果 `p[0] != s[0]`，则 `dp[(s, p)] = False`。
	- 返回 `dp[(s, p)]`。

```python [solution1-Python]
class Solution:
    def remove_duplicate_stars(self, p):
        if p == '':
            return p
        p1 = [p[0],]
        for x in p[1:]:
            if p1[-1] != '*' or p1[-1] == '*' and x != '*':
                p1.append(x)
        return ''.join(p1) 
        
    def helper(self, s, p):
        dp = self.dp
        if (s, p) in dp:
            return dp[(s, p)]

        if p == s or p == '*':
            dp[(s, p)] = True
        elif p == '' or s == '':
            dp[(s, p)] = False
        elif p[0] == s[0] or p[0] == '?':
            dp[(s, p)] = self.helper(s[1:], p[1:])
        elif p[0] == '*':
            dp[(s, p)] = self.helper(s, p[1:]) or self.helper(s[1:], p)
        else:
            dp[(s, p)] = False

        return dp[(s, p)]
        
    def isMatch(self, s, p):
        p = self.remove_duplicate_stars(p)
        # memorization hashmap to be used during the recursion
        self.dp = {}
        return self.helper(s, p)
```

**复杂度分析**

* 时间复杂度：最好的情况下 $\mathcal{O}(\min(S, P))$，最坏的情况下是 $\mathcal{O}(2^{\min(S, P/2)})$。其中 $S$ 和 $P$ 指的是输入字符串和字符模式的长度。 最好的情况很明显，让我们估算最坏的情况。最耗时的递归是字符模式上的星号形成树的情况，将执行两个分支 `helper(s, p[1:])` 和 `helper(s[1:], p)`。数据清理后字符模式中的最大星树为 $P/2$，因此时间复杂度为 $\mathcal{O}(2^{\min(S, P/2)})$。
* 空间复杂度：$\mathcal{O}(2^{\min(S, P/2)})$，用来存储记忆哈希表和递归调用堆栈。


####  方法二：动态规划
上面的递归方法体现了当递归深度大的时候有多耗时，所以我们尝试一些更迭代的方法。

第一种方法中的记忆给出了尝试动态规划的想法。这个问题和[编辑距离](https://leetcode-cn.com/problems/edit-distance/)非常相似，所以我们在这里使用完全相同的方法。

我们的想法是将问题简化为简单的问题，例如，有一个字符串 `adcebdk` 和字符模式 `*a*b?k`，计算是否匹配 `D = True/False`。我们将输入字符串和字符模式的长度 `p_len`，`s_len` 和是否匹配 `D[p_len][s_len]` 联系起来。

让我们进一步介绍 `D[p_idx][s_idx]`，`D[p_idx][s_idx]` 代表的是字符模式中的第 `p_idx` 字符和输入字符串的第 `s_idx` 字符是否匹配。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDQvZHBfbWF0Y2gyLnBuZw?x-oss-process=image/format,png)
如果字符相同或字符模式的字符为 `?`，则 
$$规则1：D[p_{idx}][s_{idx}] = D[p_{idx} - 1][s_{idx} - 1] \qquad (1)$$

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDQvd29yZF9tYXRjaDMucG5n?x-oss-process=image/format,png)
如果字符模式的字符为星号且 `D[p_idx - 1][s_idx - 1] = True`，则：
- 星号匹配完成。
- 星号继续匹配更多的字符。

$$规则 2：D[p_{idx} - 1][i] = \textrm{True}, i \ge s_{idx} - 1 \qquad(2)$$

所以，每一步的计算是基于之前完成的计算完成的。

<![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDQvaWZfbWF0Y2gucG5n?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDQvZHBzdGFyLnBuZw?x-oss-process=image/format,png)>

**算法：**

- 初始化匹配表为 `False` 除了 `D[0][0] = True`。
- 使用规则 1 和规则 2 计算表格，最后返回 `D[p_len][s_len]` 作为答案。

```python [solution2-Python]
class Solution:
    def isMatch(self, s, p):
        s_len = len(s)
        p_len = len(p)
        
        # base cases
        if p == s or p == '*':
            return True
        if p == '' or s == '':
            return False
        
        # init all matrix except [0][0] element as False
        d = [ [False] * (s_len + 1) for _ in range(p_len + 1)]
        d[0][0] = True
        
        # DP compute 
        for p_idx in range(1, p_len + 1):
            # the current character in the pattern is '*'
            if p[p_idx - 1] == '*':
                s_idx = 1
                # d[p_idx - 1][s_idx - 1] is a string-pattern match 
                # on the previous step, i.e. one character before.
                # Find the first idx in string with the previous math.
                while not d[p_idx - 1][s_idx - 1] and s_idx < s_len + 1:
                    s_idx += 1
                # If (string) matches (pattern), 
                # when (string) matches (pattern)* as well
                d[p_idx][s_idx - 1] = d[p_idx - 1][s_idx - 1]
                # If (string) matches (pattern), 
                # when (string)(whatever_characters) matches (pattern)* as well
                while s_idx < s_len + 1:
                    d[p_idx][s_idx] = True
                    s_idx += 1
            # the current character in the pattern is '?'
            elif p[p_idx - 1] == '?':
                for s_idx in range(1, s_len + 1): 
                    d[p_idx][s_idx] = d[p_idx - 1][s_idx - 1] 
            # the current character in the pattern is not '*' or '?'
            else:
                for s_idx in range(1, s_len + 1): 
                    # Match is possible if there is a previous match
                    # and current characters are the same
                    d[p_idx][s_idx] = \
                    d[p_idx - 1][s_idx - 1] and p[p_idx - 1] == s[s_idx - 1]  
                                                               
        return d[p_len][s_len]
```

```java [solution2-Java]
class Solution {
  public boolean isMatch(String s, String p) {
    int sLen = s.length(), pLen = p.length();

    // base cases
    if (p.equals(s) || p.equals("*")) return true;
    if (p.isEmpty() || s.isEmpty()) return false;

    // init all matrix except [0][0] element as False
    boolean[][] d = new boolean[pLen + 1][sLen + 1];
    d[0][0] = true;

    // DP compute
    for(int pIdx = 1; pIdx < pLen + 1; pIdx++) {
      // the current character in the pattern is '*'
      if (p.charAt(pIdx - 1) == '*') {
        int sIdx = 1;
        // d[p_idx - 1][s_idx - 1] is a string-pattern match
        // on the previous step, i.e. one character before.
        // Find the first idx in string with the previous math.
        while ((!d[pIdx - 1][sIdx - 1]) && (sIdx < sLen + 1)) sIdx++;
        // If (string) matches (pattern),
        // when (string) matches (pattern)* as well
        d[pIdx][sIdx - 1] = d[pIdx - 1][sIdx - 1];
        // If (string) matches (pattern),
        // when (string)(whatever_characters) matches (pattern)* as well
        while (sIdx < sLen + 1) d[pIdx][sIdx++] = true;
      }
      // the current character in the pattern is '?'
      else if (p.charAt(pIdx - 1) == '?') {
        for(int sIdx = 1; sIdx < sLen + 1; sIdx++)
          d[pIdx][sIdx] = d[pIdx - 1][sIdx - 1];
      }
      // the current character in the pattern is not '*' or '?'
      else {
        for(int sIdx = 1; sIdx < sLen + 1; sIdx++) {
          // Match is possible if there is a previous match
          // and current characters are the same
          d[pIdx][sIdx] = d[pIdx - 1][sIdx - 1] &&
                  (p.charAt(pIdx - 1) == s.charAt(sIdx - 1));
        }
      }
    }
    return d[pLen][sLen];
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(S P)$，其中 $S$ 和 $P$ 指的是字符模式和输入字符串的长度。
* 空间复杂度：$\mathcal{O}(S P)$，用来存储匹配表格。


####  方法三：回溯
复杂度 $\mathcal{O}(S P)$ 比 $\mathcal{O}(2^{\min(S, P/2)})$ 好的多，但是仍然有改进的余地。不需要计算整个表格，也就是检查每个星号的所有可能性：
- 匹配 0 个字符。
- 匹配 1 个字符。
- 匹配 2 个字符。

...
- 匹配所有剩余的字符。

让我们从匹配 0 个字符开始，如果这个假设导致不匹配，则回溯：回到前一个星号，假设它匹配一个字符，然后继续。若又是不匹配的情况？再次回溯：回到上一个星号，假设匹配两个字符，等等。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDQvYmFja3RyYWNrLnBuZw?x-oss-process=image/format,png)

**算法：**

我们使用两个指针：`s_idx` 遍历输入字符串，`p_idx` 遍历字符模式。当 `s_idx < s_len`：
- 如果字符模式仍有字符 `p_idx < p_len` 且指针下的字符匹配 `p[p_idx] == s[s_idx]` 或 `p[p_idx] == '?'`，则两个指针向前移动。
- 反之如果字符模式仍有字符 `p_idx < p_len` 且 `p[p_idx] == '*'`，则首先检查匹配 0 字符的情况，即只增加模式指针 `p_idx++`。记下可能回溯的位置 `star_idx` 和当前字符串的位置 `s_tmp_idx`。
- 反之如果出现不匹配的情况：
	- 如果字符模式中没有星号，则返回 `False`。
	- 如果有星号，则回溯：设置 `p_idx = star_idx + 1` 和 `s_idx = s_tmp_idx + 1`，假设这次的星匹配多个字符。则可能的回溯为 `s_tmp_idx = s_idx`。
- 如果字符模式的所有剩余字符都是星号，则返回 `True`。

```python [solution3-Python]
class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        s_len, p_len = len(s), len(p)
        s_idx = p_idx = 0
        star_idx = s_tmp_idx = -1
 
        while s_idx < s_len:
            # If the pattern caracter = string character
            # or pattern character = '?'
            if p_idx < p_len and p[p_idx] in ['?', s[s_idx]]:
                s_idx += 1
                p_idx += 1
            # If pattern character = '*'
            elif p_idx < p_len and p[p_idx] == '*':
                # Check the situation
                # when '*' matches no characters
                star_idx = p_idx
                s_tmp_idx = s_idx
                p_idx += 1
            # If pattern character != string character
            # or pattern is used up
            # and there was no '*' character in pattern 
            elif star_idx == -1:
                return False
            # If pattern character != string character
            # or pattern is used up
            # and there was '*' character in pattern before
            else:
                # Backtrack: check the situation
                # when '*' matches one more character
                p_idx = star_idx + 1
                s_idx = s_tmp_idx + 1
                s_tmp_idx = s_idx
        
        # The remaining characters in the pattern should all be '*' characters
        return all(x == '*' for x in p[p_idx:])
```

```java [solution3-Java]
class Solution {
  public boolean isMatch(String s, String p) {
    int sLen = s.length(), pLen = p.length();
    int sIdx = 0, pIdx = 0;
    int starIdx = -1, sTmpIdx = -1;

    while (sIdx < sLen) {
      // If the pattern caracter = string character
      // or pattern character = '?'
      if (pIdx < pLen && (p.charAt(pIdx) == '?' || p.charAt(pIdx) == s.charAt(sIdx))){
        ++sIdx;
        ++pIdx;
      }
      // If pattern character = '*'
      else if (pIdx < pLen && p.charAt(pIdx) == '*') {
        // Check the situation
        // when '*' matches no characters
        starIdx = pIdx;
        sTmpIdx = sIdx;
        ++pIdx;
      }
      // If pattern character != string character
      // or pattern is used up
      // and there was no '*' character in pattern 
      else if (starIdx == -1) {
        return false;
      }
      // If pattern character != string character
      // or pattern is used up
      // and there was '*' character in pattern before
      else {
        // Backtrack: check the situation
        // when '*' matches one more character
        pIdx = starIdx + 1;
        sIdx = sTmpIdx + 1;
        sTmpIdx = sIdx;
      }
    }

    // The remaining characters in the pattern should all be '*' characters
    for(int i = pIdx; i < pLen; i++)
      if (p.charAt(i) != '*') return false;
    return true;
  }
}
```

**复杂度分析**

* 时间复杂度：最好的情况下是 $\mathcal{O}(\min(S, P))$，平均情况下是 $\mathcal{O}(S \log P)$，其中 $S$ 和 $P$ 指的是字符模式和输入字符串的长度。详细证明可点击：[证明过程](https://arxiv.org/pdf/1407.0950.pdf)。
* 空间复杂度：$\mathcal{O}(1)$。