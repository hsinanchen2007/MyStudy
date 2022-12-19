**思路：**

双指针从两端往中间遍历，用两个字符串不断加入指针所指向的字符，更新并比较，相等则答案加 2，并清空字符串继续遍历。如果最后遍历完，有剩余字符串，那么答案再加 1。

![贪心正确性](https://pic.leetcode-cn.com/d7dfdee76ddadd0e308ff87577f19bcea8e34854e5a76a3bd9b4533edfa06931.png)

下面我们来简单说明一下贪心的正确性。如上图，当我们从两边向中间遍历，首先得到两个相等的字符串 `a` 的时候，如果我们不进行局部贪心，而继续扫描，那么我们找到的下一组段式回文对，前者必然要包含后缀 `a`，后者必然要包含前缀 `a`，而且中间的 `b` 字符串必然也要相等，那么这组段式回文对就一定可以拆出大于等于 3 对的段式回文对。所以局部贪心是最优的。

**图解：**

![图解](https://pic.leetcode-cn.com/472a7a423fd77f33b4e6c0596ca5b0ae919e3e0a044eb934a4e68adb88ef7168.gif)


**代码：**
```python
class Solution:
    def longestDecomposition(self, text: str) -> int:
        n = len(text)
        i, j = 0, n - 1
        str1, str2, ans = '', '', 0
        while i < j:
            str1 = str1 + text[i]
            str2 = text[j] + str2
            if str1 == str2:
                ans += 2
                str1, str2 = '', ''
            i += 1
            j -= 1
        if n % 2 == 1 or str1 != '':
            ans += 1
        return ans
```
