### 解题思路
此处撰写解题思路
注释即是

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        sn = str(x)
        # 判断负数
        if '-' in sn:
            # [::-1]字符串反转输出
            num = -int(sn[1:][::-1])
        # 判断正数
        else:
            num = int(sn[::-1])
        # 判断范围
        if num < -2**31 or num>2**31-1:
            return 0
        return num

```