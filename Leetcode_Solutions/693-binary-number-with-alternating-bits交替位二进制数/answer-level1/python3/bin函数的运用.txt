### 解题思路
- 利用函数bin将整数n转成二进制字符串，并去掉字符串开头的0b，再将其转成list列表
- 遍历列表，判断当前元素值跟下一个元素值是否相同，若相同，则直接返回False
- 如果遍历结束，则返回True

### 代码

```python3
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        # 利用函数bin将整数n转成二进制字符串，并去掉字符串开头的0b，再将其转成list列表
        # 遍历列表，判断当前元素值跟下一个元素值是否相同，若相同，则直接返回False
        # 如果遍历结束，则返回True
        get_list = list(bin(n).replace('0b', ''))
        for i in range(len(get_list)):
            if i<=len(get_list)-2:
                if get_list[i] == get_list[i+1]:
                    return False
            else:
                return True
        return True
```