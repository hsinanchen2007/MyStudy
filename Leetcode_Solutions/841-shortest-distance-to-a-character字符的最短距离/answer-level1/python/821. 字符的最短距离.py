
- 当前指向值, 匹配C, 则直接返回
- 如果不是, 则需要双指针去做匹配, 主要边界问题

```
class Solution(object):
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        L = []
        # 双指针
        for index, v in enumerate(S):
            if v == C:
                L.append(0)
            else:
                # double index
                left, right = index - 1, index + 1
                while(True):
                    if left >= 0 and right <= len(S) - 1:
                        left_v, right_v = S[left], S[right]
                        if left_v == C or right_v == C:
                            L.append(min(index - left, right - index))
                            break
                        else:
                            left, right = left - 1, right + 1
                    elif right <= len(S) - 1:
                        right_v = S[right]
                        if right_v == C:
                             L.append(right - index)
                             break
                        else:
                             right += 1
                    elif left >= 0:
                        left_v = S[left]
                        if left_v == C:
                             L.append(index - left)
                             break
                        else:
                             left -= 1
        return L
```
