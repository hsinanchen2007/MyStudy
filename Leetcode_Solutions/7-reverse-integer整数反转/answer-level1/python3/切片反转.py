### 解题思路
1. 取绝对值
2. 转为字符串
3. 使用切片反转
4. 合成结果转为int
5. 判断是否在范围内

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        y=int(''.join(list(str(abs(x))[::-1])))
        result= -int(y) if x<0 else int(y)
        return result if result>=-2**31 and result<=2**31-1 else 0
```