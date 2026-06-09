### 解题思路
1、统计相同字符出现的次数cnt
2、cnt除2取整，再*2累加
3、如果最终字符串总长大于步骤2的累加结果，则说明至少有一个字符是奇数个，最后＋1

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        count=0
        cnt=collections.Counter(s)
        
        for c in cnt:
            count+=cnt[c]//2*2
        if len(s)>count:
            count+=1
        return count
```