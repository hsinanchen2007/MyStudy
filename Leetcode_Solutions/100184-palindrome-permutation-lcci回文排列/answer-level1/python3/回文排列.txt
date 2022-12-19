### 解题思路
1.利用collections.Counter检测奇偶数

### 代码

```python3
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        from collections import Counter
        odd = 0
        counter = Counter(s)
        for key in counter.keys():
            if counter[key] % 2 == 1:
                odd += 1
            if odd > 1:
                return False
        return True

'''
作者：xilepeng
链接：https://leetcode-cn.com/problems/palindrome-permutation-lcci/solution/python3-by-xilepeng-13/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
'''
```