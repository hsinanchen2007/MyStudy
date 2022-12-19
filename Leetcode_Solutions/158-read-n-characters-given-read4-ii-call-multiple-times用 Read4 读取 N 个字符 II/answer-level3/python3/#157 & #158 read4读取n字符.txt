# 157. 只调用一次read
cursor记录当前buf更新的位置，也是read4一共读取的字符数，循环读取字符直接更新到buf里，一旦当前read4读到的字符数小于4（file读完了）或者n本来就小于等于4（不管怎样都只需要读一次read4）就停止循环，否则循环直到cursor大于等于n。

最终读取的字符数不是n就是cursor，取其中小的那一个。严谨一点的话，最后buf里不应该有多余的字符。
```
class Solution:
    def read(self, buf, n):
        cur = 0
        while cur < n:
            res = [''] * 4
            num = read4(res)
            buf[cur: cur + num] = res
            cur += num
            if num < 4 or n <= 4:
                break 
        return min(n, cur)
```
# 158. 多次调用read
多次调用read4，每次都会接着上一次的位置读取，所以需要一个类变量缓存每次多余的字符。

每次调用read时先检查上一次多余的字符够不够，够的话直接更新buf和缓存并返回n。cursor表示缓存里字符总数。循环向缓存读字符，停止条件和之前一样，最后更新buf和缓存，返回cursor和n中小的那一个。
```
class Solution:
    def __init__(self):
        self.buf = []

    def read(self, buf, n):
        buf_len = len(self.buf)

        if len(self.buf) >= n:
            buf[:n] = self.buf[:n]
            self.buf = self.buf[n:]
            return n
        
        cur = buf_len
        while cur < n:
            cache = [''] * 4
            num = read4(cache)
            self.buf += cache[:num]
            cur += num
            if num < 4 or n <= 4:
                break
        
        res = min(cur, n)
        buf[:res] = self.buf[:res]
        self.buf = self.buf[res:]
        return res
```
