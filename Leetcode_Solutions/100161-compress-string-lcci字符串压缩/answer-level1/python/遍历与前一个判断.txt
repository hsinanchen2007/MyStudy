### 解题思路
![image.png](https://pic.leetcode-cn.com/dd8c6661606b797c9f891207b2bd4cfc4c721d412e251424979d6aad2ecc77bc-image.png)
就是遍历，与前面判断，一样就计数加1，不一样就添加字符

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if S == '':
            return ''
        result = list()
        S_list = list(S)
        result.append(S[0])
        n = 1
        for i in range(1, len(S_list)):
            if (S_list[i] == S_list[i-1]):
                n += 1
            else:
                result.append(n)
                n = 1
                result.append(S_list[i])
        result.append(n)
        if len(result) >= len(S_list):
            return S
        else:
            return "".join('%s' %id for id in result)

```