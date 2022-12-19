```

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        # 思路： 出现个数为偶数的字符，个数全部相加。出现个数为奇数的字符，取-1，得到最大偶数，相加，最后再加1
        num_list = [s.count(c)//2 for c in set(s)] 
        for c in set(s):
            if s.count(c) % 2 == 1:
                return sum(num_list)*2 +1
        
        return sum(num_list)*2
```
