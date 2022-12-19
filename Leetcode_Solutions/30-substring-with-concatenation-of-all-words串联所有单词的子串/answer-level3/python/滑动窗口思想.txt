思路：因为单词长度固定，设计一个滑窗长度为每个单词的长度。通过字典need存储每个单词出现的次数，然后开始滑动窗口，后面套路和滑动窗口类似，可先做438、3等题缓冲一下。


class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        #滑动窗口
        if not words or not s:
            return None
        window = len(words[0])
        left,right = 0,window-1
        result = []
        need,have = {},{}

        for i in words:
            need[i] = need.get(i,0) + 1

        while right < len(s):
            c = s[(right-window+1):right+1]
            if c not in need:
                have.clear()
                left = left +1
                right  = left + window - 1 
            else:
                have[c] = have.get(c,0) + 1
                if right - left + 1 == window * len(words):
                    if have == need:
                        result.append(left)
                    have.clear()
                    left += 1
                    right = left + window - 1
                else:
                    right += window
        return result