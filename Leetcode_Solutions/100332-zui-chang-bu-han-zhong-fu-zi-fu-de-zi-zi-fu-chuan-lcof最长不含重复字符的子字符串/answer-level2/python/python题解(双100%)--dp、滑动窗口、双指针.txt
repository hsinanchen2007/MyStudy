### 动态规划(dp)--剑指offer官方解释
![image.png](https://pic.leetcode-cn.com/73392bc73f51ca9dc91b3f438f70b9266d8864bcc2ea8fc36a0cdb7f4717c276-image.png)
- 我们先介绍使用动态规划的思路来解决
- 首先定义函数`f(i)`为以第`i`个字符为结尾的不包含重复字符的子字符串的最长长度.我们从左到右一次扫描字符串中的每一个字符.当我们计算以第`i`个字符为结尾的不包含重复字符的子字符串的最长长度`f(i)`时,我们已经知道了`f(i-1))`
- 下面分几种情况:
1. 如果第`i`个字符在之前没有出现过,那么`f(i) = f(i-1) + 1`
2. 如果第`i`个字符在之前出现过,会出现两种情况,我们先计算下第`i`个字符和它上次出现在字符串中的位置的距离,计为`d`.
- 第一种情形是`d`小于或者等于`f(i-1)`,此时第`i`个字符上次出现在`f(i-1)`对应的最长子字符串之中,因此`f(i) = d`
- 第二种情形是`d`大于`f(i-1)`,此时第`i`个字符上次出现在`f(i-1)`对应的最长子字符串之前,因此有`f(i) = f(i-1) + 1`
- 时间复杂度`O(n)`,空间复杂度`O(n)`,使用字典保存字符出现的位置
- 我们的分析结束了,对应的转移方程也就写很容易出来了,下面为代码:
### 代码

```python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        dic = {}
        max_length = 0
        cur_length = 0
        for i in range(len(s)):
            if s[i] not in dic or i - dic[s[i]] > cur_length:
                cur_length += 1
            else:
                cur_length = i - dic[s[i]]
            dic[s[i]] = i
            if max_length < cur_length:
                max_length = cur_length
        return max_length
```

### 滑动窗口(双指针)
![image.png](https://pic.leetcode-cn.com/6be4d2af6195bda9f0e66123b8fcf82538700fbe3273e878c9ec3a381ac41613-image.png)

- 使用滑动窗口的思想进行解决
- 设定两个指针`low`和`high`分别指向窗口的尾部和头部
- 分情况解决,其实本质还是动态规划的思路:
1. 如果当前字符不在滑动窗口内的时候,比较之前的存储的最大结果与当前的滑动窗口的大小,取最大的
2. 如果当前字符在滑动串口内时,将`low`指针向前移直到当前字符不在滑动窗口内
- 算法时间复杂度`O(n**2)`,空间复杂度`O(1)`
```
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        low = 0
        for high in range(len(s)):
            if s[high] not in s[low:high]:
                result = max(high-low + 1, result)
            else:
                while s[high] in s[low:high]:
                    low += 1
        return result

```
### 滑动窗口改进(哈希表)
![image.png](https://pic.leetcode-cn.com/df7fadbbdb936e2bce0827f58992d0861e07956f556b21a9275094ffb813c65e-image.png)

- 上面的代码我们可以看到,当字符在滑动窗口内的时候,我们还需要进行一次遍历,如果我们早在之前就记录下来了字符的位置,通过直接查找,是不是会节省很多时间呢?
- 我们想到了使用哈希表,因为它的存储和查找的时间复杂度都为`O(1)`
- 算法的整体时间复杂度为`O(n)`,空间复杂度为`O(n)`
- 与上面相比较是利用空间换取了时间
### 代码
```
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        dic = {}
        tail = 0
        result = 0
        for i in range(len(s)):
            if s[i] in dic:
                tail = max(dic[s[i]] + 1, tail) #优化步骤
            dic[s[i]] = i
            result = max(result, i-tail+1)
        return result
```
