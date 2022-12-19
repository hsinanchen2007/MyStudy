### 解题思路
回文除最中间外，其他字母出现次数必然为偶数。以此为基础，统计字母出现的次数，如果为奇数，则-1后变为偶数。
需要注意的是，如果出现了奇数个数的字母，那么中间可以多放一个。回文串长度要+1

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        if len(s) <= 1:
            return len(s)
        result = 0
        cnt = [0]*58
        for v in s:
            pos = ord(v) - ord('A')
            cnt[pos] += 1
        even = 0
        for i in range(58):
            if cnt[i]%2==0:
                result += cnt[i]
            else:
                result += cnt[i]-1
                even = 1
        
        return result+even
```