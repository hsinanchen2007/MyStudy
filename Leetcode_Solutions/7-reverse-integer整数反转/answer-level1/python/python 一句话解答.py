### 解题思路
两种方案，主要是获取 x 的符号的方法不同，都是一句话


`int(str(abs(x))[::-1])` 这句可以输出 x 的无符号的反转，先把整数转字符串，在把字符串反转，再把字符串转整数
`x//abs(x)` 用于得到 x 的符号，但是对 0 不适用，所以得加 if else 表达式判断一下
`int((x+0.1)//abs(x+0.1))` 用于得到 x 的符号，由于 x 是整数，加个 0.1 不会改变符号，并解决了除 0 的问题

最后使用 if else 表达式判断范围是否在 int32 内


### 代码

方案一
```python
class Solution:
    def reverse(self, x: int) -> int:
        return (int((x+0.1)//abs(x+0.1)) * int(str(abs(x))[::-1])) if -1<<31 < ((x+0.1)//abs(x+0.1) * int(str(abs(x))[::-1])) < (1<<31)-1 else 0
```

方案二

```python
class Solution:
    def reverse(self, x: int) -> int:
        return (x//abs(x) * int(str(abs(x))[::-1])if x else 0) if -1<<31 < (x//abs(x) * int(str(abs(x))[::-1])if x else 0) < (1<<31)-1 else 0
```