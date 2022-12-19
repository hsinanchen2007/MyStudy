一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 关注交流。

### 解题思路
- 1.比较n1与n2，转成字符串s1与s2
- 2.比较s1s2与s2s1大小，小的放前面
- 3.依次输出所有字符串

### 代码

```python
import functools
def compare(s1, s2):
    if s1+s2 < s2+s1:
        return -1
    elif s1+s2 == s2+s1:
        return 0
    else:
        return 1

class Solution(object):
    def minNumber(self, numbers):
        if not numbers: return ''
        if len(numbers) == 1: return str(numbers[0])
        str_numbers = [str(n) for n in numbers]
        return ''.join(sorted(str_numbers, key=functools.cmp_to_key(compare)))
```