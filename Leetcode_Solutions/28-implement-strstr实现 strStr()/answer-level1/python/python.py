1.判断needle是否为空
2.判断needle 是否in haystack
3.找到第一个公共位置字母，并判断下面的len（needle）字段字母和needle内字母相同


class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if needle == "":
            return 0
        k = 0
        if needle in haystack:
            for x in needle:
                for i in range(len(haystack)):
                    if x == haystack[i] and haystack[i:i+len(needle)] == needle:
                        return i
        else:
            return -1