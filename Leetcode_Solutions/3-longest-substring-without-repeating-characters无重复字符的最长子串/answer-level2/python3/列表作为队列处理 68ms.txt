### 解题思路
发现自带的list比导入的queue好用= =
思路基本上就是滑动窗口

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s: return 0
        result = 0
        max_result = 0
        lst = []
        for i in s:
            if i in lst:
                for j in range(lst.index(i),-1,-1):   #删掉字符出现之前的字符（包括）
                    del lst[j]
                    result-=1    # 删几个减几个
                result+=1   #把自己加入
                lst.append(i)
            else:
                lst.append(i)
                result+=1
            if max_result<result:
                max_result = result
        return max_result
```