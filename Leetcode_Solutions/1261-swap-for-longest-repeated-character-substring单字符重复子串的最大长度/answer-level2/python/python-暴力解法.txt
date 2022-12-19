```
class Solution(object):
    def maxRepOpt1(self, text):
        """
        :type text: str
        :rtype: int
        """
        j, res = 0, 0 # j 是子串起始index
        N = len(text)
        for i in range(N):
            if text[i] != text[j]:
                n = 0
                # 处理子串左侧交换字符的情况
                lo, hi = 0, j-1
                while lo <= hi:
                    if text[lo] == text[j]:
                        n+=1
                        break
                    lo+=1
                lo, hi = i + 1, N - 1
                # 处理子串右侧交换字符的情况
                while n == 0 and lo <= hi:
                    if text[hi] == text[j]:
                        n += 1
                        hi -=1
                        break
                    hi -= 1
                # 处理交换位置后，连续出现的相同字符数量
                while lo <= hi:
                    if text[lo] == text[j]:
                        n += 1
                    else:
                        break
                    lo += 1
                res = max(res, i - j + n)
                j = i
                continue
            res = max(res, i - j + 1)
        return res

```
