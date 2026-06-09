### 解题思路
1、先统计每个字符的个数，偶数个直接加上，因为偶数个字符肯定能够成回文串，奇数个字符就只只用奇数个-1个来当回文串，这样保证奇数个字符中只选择其中偶数个来当作回文字符串
2、最后需要判断一下得到的长度和总长度是否相等，如果相等，说明原始字符中全是偶数个，如果要小于原始字符串，说明存在奇数个的字符，那么就把长度+1，是因为只能允许一个奇数的字符串放在整个字符串的最中间位置。
### 代码

```

class Solution:
    def longestPalindrome(self, s: str) -> int:
        ##回文串：正序，逆序都相同，如果当前字符串的个数是偶数个，那么一定能成回文串，当前字符串的个数为奇数个，也能成为回文串，但是要放中间

        ##特殊情况处理
        if not s:
            return 0
        if len(s)==1:
            return 1

        from collections import Counter
        ss = Counter(s) #eg:{"a":1,"b":1,"c":4,"d":2}
        Longs = 0
        for key,value in ss.items():
            print(key,value)
            if value%2==0:##偶数个
                Longs+=value
            else:
                Longs+=value-1
              
        return Longs+1 if Longs<len(s) else Longs

```