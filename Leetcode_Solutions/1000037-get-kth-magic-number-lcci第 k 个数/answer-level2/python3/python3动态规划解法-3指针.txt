采用了大多数人的方法，即由于后面的数一定是前面的数的倍数，所以用三个指针分别存储要和3、5、7相乘的数所处位置，每次得到一个结果即要将乘积等于该数的指针加一，以防出现重复情况。
代码如下：
```
class Solution:
    def minThree(self, a, b, c):
        if a<=b:
            if a<=c:
                return a
            return c
        else:
            if b<=c:
                return b
            return c

    def getKthMagicNumber(self, k: int) -> int:
        tag1, tag2, tag3 = 0,0,0
        mul = [1]
        if k==1:
            return 1
        for i in range(k-1):
            mul.append(self.minThree(3*mul[tag1], 5*mul[tag2], 7*mul[tag3]))
            if mul[-1] == 3*mul[tag1]:
                tag1 += 1
            if mul[-1] == 5*mul[tag2]:
                tag2 += 1
            if mul[-1] == 7*mul[tag3]:
                tag3 += 1
        return mul[-1]
```
这个想法应该比较简单易懂了~