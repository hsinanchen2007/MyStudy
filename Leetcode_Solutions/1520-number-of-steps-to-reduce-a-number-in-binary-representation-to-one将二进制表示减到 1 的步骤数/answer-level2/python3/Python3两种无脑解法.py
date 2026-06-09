比赛的时候真的想无节操地写成下面这样了，简单的模拟：
```python3
c = 0
n = int(s, base=2)
while n != 1:
    c += 1
    if n % 2 == 0:
        n //= 2
    else:
        n += 1
return c
```
犹豫了几秒钟，好像Java和Python3是可以无脑操作，C/C++的小伙伴可能不行？为了公平比赛还是老老实实写了字符串操作：

```python3
a = [ch for ch in s]
count = 0
while len(a) > 1:
    if a[-1] == '0':
        a.pop()
        count += 1
    else:
        count += 1
        while len(a) > 0 and a[-1] == '1':
            a.pop()
            count += 1
        if len(a) > 0:
            a[-1] = '1'
        else:
            a.append('1')
return count
```
思路大概是这样子，分两种情形：
1、偶数（末位是0）：没什么好说的，删掉末尾的0就行了；
2、奇数（末位有连续的n位是1，n >= 1）：
这样来思考一下，奇数的话末位是XXXXXXXXXXX01111111111的样子，加1之后变为XXXXXXXXXXX10000000000，之后n步操作会是连续的把新增的这些0去掉，所以一并处理掉就好了。

显然，总操作次数是执行a.pop()次数的常数倍，a.pop()至多执行len(s)次，所以时间复杂度O(len(s))

