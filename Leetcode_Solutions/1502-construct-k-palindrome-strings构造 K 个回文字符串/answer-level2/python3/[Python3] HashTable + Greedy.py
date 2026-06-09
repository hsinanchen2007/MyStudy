【分析】HashTable + Greedy
（1）首先获取串s长度n，显然若n < k，凑不成k个回文串返回false；若n == k，则恰可以凑成k个回文串，返回true；
（2）统计串s中各小写字母出现次数，然后统计出现次数为奇数次的小写字母个数ans；
（3）根据回文串特性：每个回文串中出现次数为奇数的字符最多有一种，而出现次数为偶数的字符可以有若干种，因此ans必须 <= k才能恰好凑成k个回文串。故返回是否满足(ans <= k)即可。
时间复杂度O(n), 空间复杂度O(n)。
```
class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        n = len(s)
        if n < k: return False
        elif n == k: return True
        
        ans, odd = [0] * 26, 0
        for i in range(len(s)):
            ans[ord(s[i]) - 97] += 1
        for i in range(26):
            if ans[i] % 2 == 1:
                odd += 1
        return odd <= k
```
