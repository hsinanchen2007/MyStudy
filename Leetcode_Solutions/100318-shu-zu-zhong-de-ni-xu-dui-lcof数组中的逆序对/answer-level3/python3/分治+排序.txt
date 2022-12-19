### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reversePairs(self, nums) -> int:
        self.ans = 0
        def div(s):
            if len(s)<=1:return s
            mid = len(s)//2
            s = div(s[:mid]) + div(s[mid:])
            i,j = mid-1,len(s)-1
            while i>=0 and j>=mid:
                if s[i]>s[j]:self.ans += j-mid+1;i -= 1
                else:j -= 1
            return sorted(s)
        div(nums)
        return self.ans


```