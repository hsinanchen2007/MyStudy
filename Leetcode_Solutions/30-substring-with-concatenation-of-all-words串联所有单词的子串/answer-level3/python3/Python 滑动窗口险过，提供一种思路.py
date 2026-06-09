![image.png](https://pic.leetcode-cn.com/0e67690c8121693629e6191b11da676bb1c0956c82c8375e123653f62cc6208d-image.png)


```
from typing import List
from collections import Counter
from copy import deepcopy

'''
先统计出来所哟可能出现words中单词的起止位置，然后用一个长度为 words中单词长度总和
的滑动窗口往右边滑动，根据单词起止位置维护窗口中可能包含的单词数量，只有当单词数量
超过words中单词数量时候，窗口包裹的子字符串才可能是一个候选，然后判断候选子字符串
是否合法，递归从子字符串开头拿掉出现在words中的前缀，最后子字符串如果能变空，就是
合法的
'''


class Solution:
    def isValid(self, s, start, end, start_map, c: Counter) -> bool:
        if start == end+1 and sum(c.values()) == 0:
            return True

        if start not in start_map:
            return False

        for e in start_map[start]:
            del_word = s[start: e+1]
            if del_word not in c or c[del_word] == 0:
                continue

            c[del_word] -= 1
            if self.isValid(s, e+1, end, start_map, c):
                c[del_word] += 1
                return True

            c[del_word] += 1

        return False

    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if s == '' or len(words) == 0:
            return []

        start_map = {}      # 键值对，s中可能出现的单词的起止位置
        end_map = {}

        total_len = 0
        for word in words:
            total_len += len(word)

        if len(s) < total_len:
            return []

        for word in words:
            idx = -1
            while True:
                idx = s.find(word, idx + 1)
                if idx == -1:
                    break

                start, end = idx, idx + len(word) - 1
                if start not in start_map:
                    start_map[start] = set()
                start_map[start].add(end)

                if end not in end_map:
                    end_map[end] = []
                end_map[end].append(start)

        # 滑动窗口往右边滑动，统计窗口中出现的单词个数
        word_cnt = 0
        for i in range(total_len):
            if i in end_map:
                word_cnt += len(end_map[i])

        start, end = 0, total_len - 1
        ans = []
        c = Counter(words)
        while True:
            if word_cnt >= len(words):
                if self.isValid(s, start, end, start_map, deepcopy(c)):
                    ans.append(start)

            if end == len(s) - 1:
                break

            if start in start_map:
                word_cnt -= len(start_map[start])
            if end + 1 in end_map:
                word_cnt += len(end_map[end+1])
            start, end = start + 1, end + 1

        return ans
```
