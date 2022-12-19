### 解题思路
1. 令前len(num)-k个字符num[:len(num)-k]为所需结果res；
2. 遍历i in range(len(num)-k, len(num))，每次增加一个字符，思考如何更改res；
    (1) 从左向右遍历res，如果存在res[k]>res[k+1]的情况，则应移除res[k]，将num[i]增加到res的最后；具体见代码

### 代码

```python3
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        length = len(num)
        if length == 0 or length == k:
            return '0'

        # 假设前length-k个为返回值
        res = num[:length-k]
        j = 0
        # 遍历num[length-k:]
        for i in range(length-k, length):
            # 在res后增加num[i]观察如何更改现有的res
            res += num[i]
            # 从左向右遍历res
            while j < length-k:
                # 如果res[j] > res[j+1]，则显然res[:j]+res[j+1:] < res[:-1]，并且为所有更改方案中最小
                if res[j] > res[j+1]:
                    res = res[:j]+res[j+1:]
                    # 注意将j回退一个，要重新判断res[j-1]与res[j+1]之间的大小关系
                    j = j-1 if j>0 else 0
                    break
                j += 1
            else:
                # 如果res为的字符为递增，则增加的res[-1]字符直接删除
                res = res[:-1]
                # 注意此时j需要回退2格，下次循环需要重要判断res[-2]与res[-1]之间的大小关系
                j = j-2 if j-2>0 else 0
        
        
        return str(int(res))
```