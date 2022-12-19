通过统计字符个数来计算的方法。
```
class Solution:
    def longestPalindrome(self, s: str) -> int:
        d = {key:0 for key in s}
        # 统计每个字符出现的次数
        for c in s:
            d[c] += 1
        # 当前能构成回文的字符长度
        lenP = 0
        # 字符出现次数为偶数个的字符数
        count = 0
        for l in d.values():
            # 如果是偶数个，则最大回文串中肯定包含该字符
            if l % 2 == 0:
                lenP += l
                count += 1
            # 如果不是偶数个并且大于一，则-1后变为偶数个，就可以加入最长回文串
            elif l > 1:
                lenP += l - 1
        # 如果是每个字符出现的次数全为偶数，则最大长度已经算出来了
        # 如果不全为偶数，则随便找一个字符放在偶数字符中间，即可构成回文串，即长度+1        
        return lenP if count == len(d.values()) else lenP + 1
```
