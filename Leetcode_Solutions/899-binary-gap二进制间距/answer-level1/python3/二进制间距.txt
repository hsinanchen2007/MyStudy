### 解题思路
1.将整数转换成二进制数
2.遍历二进制数，并将1的位置存到列表l中
3.遍历列表l，并计算差值，将差值存到列表m
4.返回列表m中的最大值

### 代码

```python3
class Solution:
    def binaryGap(self, N: int) -> int:
        s = bin(N)
        l = []
        m = []
        if s.count("1") <= 1:
            return 0
        else:
            for i in range(len(s)):
                if s[i] == "1":
                    l.append(i)
            for j in range(1,len(l)):
                m.append(l[j]-l[j-1])
            return max(m)
```