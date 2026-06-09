### 解题思路
本题直接计算就可以，需要注意几个细节：
1. 字母计数需要转换成String类型
2. 直接计算时尾部需要特别的处理一下

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if len(S) == 0:
            return S
        ret = S[0]
        count = 1

        for i in range(1, len(S)):
            if S[i] == ret[-1]:
                count += 1
            else:
                ret += str(count)
                ret += S[i]
                count = 1
        
        ret += str(count)

        if len(ret) < len(S):
            return ret
        else:
            return S 
```