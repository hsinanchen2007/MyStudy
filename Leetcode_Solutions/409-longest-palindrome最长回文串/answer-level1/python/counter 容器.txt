### 解题思路
此处撰写解题思路

### 代码

```python
class Solution:
    def longestPalindrome(self, s):
        ans = 0
        count = collections.Counter(s)   #f构建新容器，统计各个元素c字母出现次数 a：5 形式
        for v in count.values():
            ans += v // 2 * 2   
            #5得4  4得4  算法
    
            if ans % 2 == 0 and v % 2 == 1:
                ans += 1
        return ans
```