### 解题思路
用python暴力肯定是会超时的。
所以有没有更好的办法呢？
我们可以模拟数字相加的过程，同一个分位上的数组相加，对10取余，就能得到对应分为上的结果。什么意思呢，举个例子
126 +
247
6+7对10取余，得到3，然后进位1
2+4+1对10取余，得到7，进位0
1+2对10取余，得到3
所以最后结果是371

再看题目也是一样的，只是我们不知道这些字母对应的数字是什么。
但是我们可以借鉴几个数相加的过程，首先对words低位的数相加，然后取余
由于不知道每个字母对应的数字，所以这个过程需要不断尝试，对words中低位的字母尝试不同的对应数字，如果取余刚好等于result对应位字母的数字，那这就是一个暂时合法的组合，我们可以往后计算下一位；不然的话尝试其他组合。

最后当计算的位超过所有word和result的长度，说明前面的位取余都相等，找到了一个映射满足条件，就可以返回True啦。

### 代码

```python3
import itertools

class Solution:
    def isSolvable(self, words, result):
        chs = list(set(words[0]) | set(words[1]) | set(result))
        if len(chs) > 10:
            return False
        words = [word[::-1] for word in words]
        result = result[::-1]
        end = max([len(word) for word in words+[result]])
        digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

        def backtrace(ch2num, carry, i):
            if i == end:
                return True
            chars = [word[i] for word in words+[result] if i < len(word)]
            unMaped = set([ch for ch in chars if ch not in ch2num])

            if unMaped:
                unMaped = list(unMaped)
                remain = digits - set(ch2num.values())
                for candi in itertools.permutations(remain, len(unMaped)):
                    for c, num in zip(unMaped, candi):
                        ch2num[c] = num
                    cursum = sum(ch2num[ch] for ch in chars[:-1]) + carry
                    tar = 0 if i >= len(result) else ch2num[result[i]]
                    if cursum % 10 == tar:
                        if backtrace(ch2num, cursum//10, i+1):
                            return True
                    for c in unMaped:
                        del ch2num[c]
            else:
                cursum = sum(ch2num[ch] for ch in chars[:-1]) + carry
                tar = 0 if i >= len(result) else ch2num[result[i]]
                if cursum % 10 == tar:
                    return backtrace(ch2num, cursum // 10, i + 1)

            return False

        return backtrace({}, 0, 0)
```