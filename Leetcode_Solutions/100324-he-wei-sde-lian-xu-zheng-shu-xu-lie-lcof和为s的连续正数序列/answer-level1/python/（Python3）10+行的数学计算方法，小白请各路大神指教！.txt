### 解题思路
![image.png](https://pic.leetcode-cn.com/6240a01a058d718a1aaba678da4bc33cec008d39aca45f10e032d229fc2648b8-image.png)
时间是长了点，但是架不住内存低啊！


1、假设连续整数列的第一个数是x，则，该数列就是 x+x+1+x+2+...+x+n，简化得到的结果是n * x+(n-1) * n * 0.5
2、由1得到 target = n * x+(n-1) * n * 0.5，计算得到 x 的值： x = (2 * target + n - n * n) % (2 * n)
3、整数列最大的元素个数不超过target/2
4、排除掉负数的情况就需要(2 * target + n - n * n)>0,不能等于零是因为存在以0开头的整数列
5、循环执行是从大整数列往小的整数列开始，（n越小，整数列元素越少，元素值越大）
6、将列表翻转，从小到大排列！

### 代码

```python
class Solution(object):
    def findContinuousSequence(self, target):
        """
        :type target: int
        :rtype: List[List[int]]
        """
        y = target
        res = []
        n = 2
        while n <= int(y // 2):
            l1 = []
            if (2 * y + n - n * n) % (2 * n) == 0 and (2 * y + n - n * n) > 0 :
                x = int((2 * y + n - n * n) // (2 * n))
                for i in range(n):
                    l1.append(x + i)
                res.append(l1)   #试过使用extend(),结果是res列表的元素不是列表形式
            n += 1
        S = res[::-1]
        return S
```