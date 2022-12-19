#### 提醒：本文尝试说明的是滑动窗口法的优化，阅读前可能需要您对滑动窗口法有个基本的概念（可[参考Java题解中的图解](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/hua-jie-suan-fa-3-wu-zhong-fu-zi-fu-de-zui-chang-z/)）。
#### 分析（引用自 [@西凉阿土伯](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/python-hua-dong-chuang-kou-xun-xu-jian-jin-de-3ge-/126069)）：
 - 三种方法的"术"是相同的(都是滑动窗口),差别在"技"上 - 1.``容器`` 2.``指针`` 3.``Hash``
 - 方法1中容器的伸缩**涉及内存分配**,所以方法2换成位置指针**省掉了内存分配**
 - 方法2位置指针还是要**扫描重复字符**,所以方法3用Hash直接判断**省掉了扫描开销**.
## 使用容器（数组） - 直观的滑动窗口法
#### 说明：
 - 使用数组作为滑动窗口
#### 效率：
> Runtime: 84 ms, faster than 24.68% of Python online submissions for Longest Substring Without Repeating Characters.
> Memory Usage: 12.1 MB, less than 48.07% of Python online submissions for Longest Substring Without Repeating Characters.
#### 复杂度分析：
 - 时间复杂度：$O(N)$
 - 空间复杂度：$O(N)$
#### 代码：
```Python
class Solution(object):
    
    def lengthOfLongestSubstring(self, s: str) -> int:
        # 字符串为空则返回零
        if not s:
            return 0

        window = []     # 滑动窗口数组
        max_length = 0  # 最长串长度

        # 遍历字符串
        for c in s:
            # 如果字符不在滑动窗口中，则直接扩展窗口
            if c not in window:
                # 使用当前字符扩展窗口
                window.append(c)
            # 如果字符在滑动窗口中，则
            # 1. 从窗口中移除重复字符及之前的字符串部分
            # 2. 再扩展窗口
            else:
                # 从窗口中移除重复字符及之前的字符串部分，新字符串即为无重复字符的字符串
                window[:] = window[window.index(c) + 1:]
                # 扩展窗口
                window.append(c)

            # 更新最大长度
            max_length = max(len(window), max_length)

        return max_length if max_length != 0 else len(s)
```

## 使用指针 - 滑动窗口优化 - 双指针法 - 使用数组索引，标记滑动窗口
#### 说明：
 - 直观的滑动窗口方法需要维护数组的增删，实际上比较耗时
 - 使用双指针（索引），记录滑动窗口起始和结束的索引值，可以减除数组增删操作，提高效率
 - 代码结构和上一种方法基本一致，只不过使用指针位移以及从原数组中截取，代替原来的窗口元素增删操作
#### 效率：
> Runtime: 40 ms, faster than 84.23% of Python online submissions for Longest Substring Without Repeating Characters.
> Memory Usage: 12.1 MB, less than 54.97% of Python online submissions for Longest Substring Without Repeating Characters.
#### 复杂度分析：
 - 时间复杂度：$O(N)$
 - 空间复杂度：$O(N)$
#### 代码：
```Python
class Solution4(object):

    def lengthOfLongestSubstring(self, s: str) -> int:
        # 字符串为空则返回零
        if not s:
            return 0

        max_length = 0      # 滑动窗口数组
        left, right = 0, 0  # 双指针

        for i, c in enumerate(s):
            # 如果字符不在滑动窗口中，则直接扩展窗口
            if c not in s[left:right]:
                # 右指针右移一位
                right += 1
            # 如果字符在滑动窗口中，则
            # 1. 从窗口中移除重复字符及之前的字符串部分
            # 2. 再扩展窗口
            else:
                # 在滑动窗口范围内中找出对应的首个字符的索引X，对应的新的左指针位置为X + 1
                # 左指针右移 索引X增一 位
                left += s[left:right].index(c) + 1
                # 右指针右移一位
                right += 1

            # 更新最大长度
            max_length = max(right - left, max_length)

        # 如果最大长度不为零，返回最大长度
        # 如果最大长度仍为零，则说明遍历整个字符串都没有发现重复字符，最大长度即为字符串本身的长度
        return max_length if max_length != 0 else len(s)
```

## 使用Hash（字典） - 滑动窗口优化
#### 说明：
 - 使用字典记录任意字符最近的索引值，字典查询时间复杂度为O(1)，相比数组查询，效率更高
 - 该算法的难点在于理解什么是``可抛弃字符串的索引尾值``，以及为什么需要``dic[c] > start``的判断
#### 效率：
> Runtime: 28 ms, faster than 99.26% of Python online submissions for Longest Substring Without Repeating Characters.
> Memory Usage: 11.8 MB, less than 99.45% of Python online submissions for Longest Substring Without Repeating Characters.
#### 复杂度分析：
 - 时间复杂度：$O(N)$
 - 空间复杂度：$O(N)$
#### 代码：
```Python
class Solution(object):

    def lengthOfLongestSubstring(self, s: str) -> int:
        # 可抛弃字符串的索引尾值 - 字符串索引值，该索引值以及之前的字符都属于重复字符串中的一部分，不再在计算中涉及
        ignore_str_index_end = -1
        dic = {}        # 任意字符最后出现在索引的位置 - {字符: 字符索引值}
        max_length = 0  # 最长字符串长度

        for i, c in enumerate(s):
            # 如果字典中已经存在字符c，则字符c重复
            # 如果字符索引值大于ignore_str_index_end，则字符c在需处理的范围内（补充说明请参考备注一）
            if c in dic and dic[c] > ignore_str_index_end:
                # 先更新可抛弃字符串的索引尾值为字符c上一次的索引值
                ignore_str_index_end = dic[c]
                # 再更新字符c的索引值
                dic[c] = i
            # 否则，
            else:
                # 更新字符最近的索引位置
                dic[c] = i
                # 更新最大长度
                max_length = max(i - ignore_str_index_end, max_length)

        return max_length
```
#### 备注一：
 1. 假设有字符串``"abbcda"``, 观察可知最长不重复子串为``"bcda"``
 2. 根据编写的算法，在刚遍历至最后一个``'a'``时，dic['a']的值为0，此时ignore_str_index_end的值已经更新为索引``1``，索引``1``以及之前的字符都是出现在重复字符之前，不用再在运算中考虑的字符。
 3. ``ignore_str_index_end``的注释，是``可抛弃字符串的索引尾值``，是双指针方法中左指针（起始针）的反面;
 4. 如果仍然不好理解，可以做到理解双指针法也行，毕竟ignore_str_index_end的确有点绕...