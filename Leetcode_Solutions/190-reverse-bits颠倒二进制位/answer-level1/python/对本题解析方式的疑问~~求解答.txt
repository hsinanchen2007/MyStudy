我们知道,
- python默认会将0开头的数字按8进制处理,比如0011会被识别为十进制的9,而不是3,
- 如果数字识别错误了,再怎么翻转肯定也得不到正确的结果

问题来了, 假设我们的输入是0011,
- 官方的解释器是先将输入按字符串处理,先转成整形,然后调用翻转函数, int("0011") == 10进制的11 == 二进制的0b1011, 即相当于调用了self.reverseBits(0b1011) == 3489660928(0b11010000000000000000000000000000) ,很明显,与正确答案不符
- 若直接按self.reverseBits(0011)调用,  0011 == 10进制的9 == 二进制的0b1001,即相当于调用了self.reverseBits(0b1001) == 2415919104(0b10010000000000000000000000000000) ,很明显,与正确答案不符
- 若直接按self.reverseBits(0b0011)调用, 0b0011 == 10进制的3, 即相当于调用了self.reverseBits(0b0011) ==   3221225472 (0b11000000000000000000000000000000), 这才是正确答案

从上面我们可以知道,对同一输入的数字,我们可以有3种解释,但只有第三种解释是合理的,正确的
但从官方的playground看,只是按第一种方法解释的,这种解释方式是错误的,但最终得到了正确的结果??wtf??
各位是怎么看的,这点很困惑,求解答~~

下面附上官方的完整代码,完全看不出来做了特殊处理啊(只是对输入转成了int):

```python
class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        result = 0
        for i in range(0, 32):
            result += (1 & n >> i) << (31 - i)
        
        return result

def stringToInt(input):
    return int(input)

def intToString(input):
    if input is None:
        input = 0
    return str(input)

def main():
    import sys
    def readlines():
        for line in sys.stdin:
            yield line.strip('\n')
    lines = readlines()
    while True:
        try:
            line = lines.next()
            n = stringToInt(line)
            
            ret = Solution().reverseBits(n)

            out = intToString(ret)
            print out
        except StopIteration:
            break

if __name__ == '__main__':
    main()
```
