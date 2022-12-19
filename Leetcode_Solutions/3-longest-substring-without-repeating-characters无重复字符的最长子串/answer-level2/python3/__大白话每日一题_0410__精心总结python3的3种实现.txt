# <<大白话每日一题_0410>>精心总结python3的3种实现

"""
题目:
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。


注意:
    计算长度的方式有两种:
        1. 直接对列表求长度: len(lst)
        2. 记录左右两端的索引位置, 手动计算长度:  right_pointer - left_pointer
    手动计算长度的方法:
        1. 右 - 左 -1:  同时不包含左右两边的点
        2. 右 - 左:  只包含左边或右边的'其中一点'
        3. 右 - 左 +1:  同时包含左右两边的点
"""

class Solution:

    # 方法一: 最容易想到的方法 (两层遍历; 需要开辟多个空间存储,占用较多内存)
    # 复杂度: O(n^2)
    def lengthOfLongestSubstring(self, s: str) -> int:
        all_length = [] # 存放"所有"的'不重复字符串'的长度
        lst = [] # 存储当前'无重复'的所有元素的列表.
        for i in s:
            # 如果重复了: 1.把当前的长度存入all_length 2.把lst中重复元素之前的元素都删掉
            if i in lst:
                all_length.append(len(lst))
                start_index = lst.index(i) + 1 # '重复元素'在lst中的位置
                lst = lst[start_index:]
            lst.append(i)
        all_length.append(len(lst))
        longest_length = max(all_length)
        return longest_length
    # 执行用时 : 64 ms , 在所有 Python3 提交中击败了 87.00% 的用户
    # 内存消耗 : 13.8 MB , 在所有 Python3 提交中击败了 5.02% 的用户


    # 方法二: 优化方法
        # 优化1: 使用数字longest_length: 一个int来替代lst (避免开辟新的存储空间)
        # 优化2: 使用双指针: 替代列表对象 (避免开辟多余列表空间: 仅有两个'指针变量')
        # todo: 如何处理最后一段无重复序列? (在循坏之外独立处理..可能不太好)
    # 复杂度: O(n^2)
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest_length = 0 # 记录'最长序列'的长度
        left_index, right_index = 0, 0 # 初始化指针位置
        for right_index, e in enumerate(s):
            slice = s[left_index : right_index] # 能取到左边, 不能取到右边
            if e in slice: # 如果新取到的元素, 在指针范围内的'切片'中'能找到' [即: 有重复值]
                length = right_index - left_index # 计算该'无重复序列'的长度
                longest_length = max(length, longest_length) # 取大值更新longest_length
                # 左指针应该放在'前一个重复元素'的'右边' (这样才不会在下次计算的时候取到上一个重复元素)
                left_index = left_index + slice.index(e) + 1
        # 当整个序列s都没有重复的情况下, 需要单独考虑
        length = len(s) - left_index
        longest_length = max(length, longest_length)
        return longest_length
    # 执行用时 : 56 ms , 在所有 Python3 提交中击败了 96.41% 的用户
    # 内存消耗 : 13.7 MB , 在所有 Python3 提交中击败了 5.02% 的用户
    # todo: 内存消耗问题还是很大!!怎么解决??


    """
    方法三: 使用双指针 + 哈希表记录和获取已读索引
    # 复杂度: O(n)
        思路:
            1. 使用字典的哈希表记录索引: 取代了 <方法一> 中的列表存储
                寻找元素的速度: 列表: O(n) 字典: O(1)

            2. 长度的计算并不一定要等到发现'重复序列'后再计算!
                可以每次都计算, 这样当发生"s中无重复序列"的情况时, 也可以应对

        问题:
            1. 如何精准,快速计算 '两个指针之间的长度'??    <<+-1的问题>>
                i. 先定义长度的涵义: 长度计算是否包含"左右指针的所在位置"
                ii. 计算:
                    1. 如果只包含其中一个指针的位置: right_index - left_index
                    2. 两个指针都包含: right_index - left_index + 1
                    3. 两个指针都不包含: right_index - left_index - 1
                    (个人之前碰到这类问题要反应一段时间, 建议直接背下来套用)

        想法:
            1. 有时候, 没有必要为了一些极少数的输入,比如"", " "值, 而强行统一'判断标准'.
               其实完全可以当做特殊情况, 单独return一个数就行
               (我看LeetCode上很多朋友的题解都是这样, 特殊情况单独return的...)
    """
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest_length = 0 # 记录'最长序列'的长度
        left_index = 0
        d = {}
        for right_index, e in enumerate(s):
            # 取出d中记录的 'e元素' 的上一个重复元素的索引位
            index = d.get(e)
            if index is not None: # 如果找到了d中的索引位, 说明"发现了重复序列"
                ### 解释: 窗口, 指当前左右指针范围内的元素
                if index >= left_index: # 当'上一个重复元素的索引位' 在 "左指针" 的右边时: 指当前记录的'窗口'中发现了'重复'
                    left_index = index + 1 # 将"左指针"移到 "上一个重复元素的右边位置"
                else: # 当'上一个重复元素的索引位' 在 "左指针" 的左边时: 并不是在当前的'窗口'发现'重复', 所以这个元素可以当做新元素添加到'd'中
                    d[e] = right_index
            # 强调: (本题的关键) [这个长度的计算纠结了很久]
                ### 因为for循环中的 right_index 的最大值是 len(s)-1, 所以想要包含最后一个字符, 必须把'right_index'向右平移1
                ### 即: 把 (right_index+1) 看成是一个整体  [可能有点绕, 如果有更好的解释, 欢迎交流~~]
            this_length = (right_index+1) - left_index
                # 每一次循环都去比较最大值 (虽然增加了计算量, 但在'没有重复序列的情况'可以正常计算最长长度)
            longest_length = max(this_length, longest_length)
                # 在d中更新每个新扫描到的元素的 '索引位'
            d[e] = right_index
        return longest_length
        # 执行用时 : 68 ms , 在所有 Python3 提交中击败了 80.39% 的用户
        # 内存消耗 : 13.9 MB , 在所有 Python3 提交中击败了 5.30% 的用户
        "正常来说这个算法的时间复杂度会低很多, 但是结果并不如人意...期待有缘人来告诉我..."




s = ""
s = " "
s = "pwwkew"
s = "dvdf"
res = Solution().lengthOfLongestSubstring(s)
print(res)













##
