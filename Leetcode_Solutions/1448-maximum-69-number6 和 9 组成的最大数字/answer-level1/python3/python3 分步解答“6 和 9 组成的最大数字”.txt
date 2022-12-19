### 解题思路
其实这一题十分简单，只有两种情况：
1.里面含有“6”
2.里面没有“6”

1.里面含有“6”：首先将获得的数字转换为字符串并转化为列表，然后只要运用一个for循环，用len（）获取数组长度，一个一个检测当前项是否为“6”，直到把每一项遍历一遍或者发现当前项为“6”，替换第一个“6”为“9”。
2.里面没有“6”：这个更简单，可以用not in 来判断这个列表中是否含有“6”这一项。
不过还没完！
最后要将列表先转化为字符串，也就是''.join()，然后将字符串转化为数字int()，用return输出。

### 代码

```python3
class Solution:
    def maximum69Number (self, num):
        a = list(str(num))
        for i in range(0,len(a)):
            if a[i] == "6":
                a[i] = "9"
                return int(''.join(a))
            elif "6" not in a:
                return int(''.join(a))
```