### 解题思路
此处撰写解题思路
1. 将整数取绝对值，形成字符串，反转，再形成整数，如果有负号就加个负号；
2. 写个条件判断，看所得数是否在规定区间
### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        rst = (int(str(abs(x))[::-1]) if x>0 else -int(str(abs(x))[::-1]))
        if rst in range(-pow(2,31)-1,pow(2,31)):
            return rst
        else:
            return 0

```