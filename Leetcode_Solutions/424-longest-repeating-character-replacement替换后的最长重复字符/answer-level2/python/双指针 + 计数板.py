### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        lens = len(s)
        if lens<=k+1:
            return lens
        # 初始化：ord得到字符的order，chr将数字转char
        counter = {}
        for i in range(ord('A'), ord('Z')+1):
            counter[chr(i)]=0
        ans = 0 # 累计最大值
        maxw = 0 # 当前窗口最多元素的数量
        start = 0 # 头指针
        for end in range(lens):
            counter[s[end]] += 1 # 遍历所有以s[end]结尾的窗口
            maxw = max(counter.values())
            while end>start and end-start+1 - maxw > k:
                counter[s[start]] -= 1 # 更新技术板
                start+=1 # 更新头指针
                maxw = max(counter.values()) # 更新最多值数量
            ans = max(ans, end-start+1)
        return ans
            
```
时间复杂度O(n*2)
