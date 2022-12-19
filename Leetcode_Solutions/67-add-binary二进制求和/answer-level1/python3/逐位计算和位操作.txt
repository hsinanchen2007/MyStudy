### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        n = max(len(a), len(b))
        # 记住zifll的用法
        a = a.zfill(n)
        b = b.zfill(n)
        carry = 0
        res = ''
        # 需要carry作为全局的变量再循环过程中记录进位的情况
        for i in range(n - 1, -1, -1):
            if a[i] == '1':
                carry += 1
            if b[i] == '1':
                carry += 1
            # 区分 (0, 0) (1, 1) (0, 1) (1, 0)四种情况
            if carry % 2 == 1:
                res = '1' + res
            else:
                res = '0' + res
            carry //= 2
        return '1' + res if carry == 1 else res

    # 方法三：位操作
    def addBinary(self, a: str, b: str) -> str:
        # 转换为10进制
        x, y = int(a, 2), int(b, 2)
        # 抑或结果为无进位的和
        # 与的结果为进位
        while y:
            x, y = x ^ y, (x & y) << 1
        return bin(x)[2:]       


```