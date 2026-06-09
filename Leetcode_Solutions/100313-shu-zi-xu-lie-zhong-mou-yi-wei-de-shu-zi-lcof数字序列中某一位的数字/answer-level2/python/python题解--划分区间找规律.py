### 划分区间减少判断次数
- 看到这个问题直接能想到的思路就是从头开始遍历数字,一个一个的想加,知道找到第n个数字为止,对于大数这样的方法效率是很差的,于是想到了能否减少一些统计的次数,这就是如下所要说的规律
- 我们下来看下每个位数的区间内各有多少位的数字:
![image.png](https://pic.leetcode-cn.com/e8dcbe08c4bafe10ba68587380e2230af72595bf883072e46089953d8f03e42e-image.png)
- 假如让我们统计第991位数,那0~9和10~99之间的数就不用统计进去了,因为999-9-180 = 810, (减去9是因为下标从0开始),现在只需要统计从100开使得第810位是哪个数字了,因为 810<2700.

### 代码

```python
class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 9:
            return n
        m = 2
        temp = 90
        n -= 9
        while n > m * temp:#找到当前的n所在的区间
            n -= m*temp
            m += 1
            temp *= 10
        temp1 = n % m
        temp2 = n // m
        if temp2:#不是否为序列的第一个数字
            if n % m: #有余数
                return int(str(10**(m-1) + (n // m))[temp1-1])
            else:#没有余数
                return int(str(10**(m-1) + (n // m)-1)[temp1-1])
        else:#是第一个数字
            return int(str(10**(m-1))[temp1-1])



            
```