### 创建左右数组
![image.png](https://pic.leetcode-cn.com/44ed3e709cea3b00755682476d88cb8b2c3d3abba6224eae3cc476b00de7d032-image.png)
- 题目给定的要求是`B[i] = A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]`
- 直接能想到是用除法做,但题目要求不能使用除法
- 我们可以将`B[i]`看做`C[i] = A[0]×A[1]×…×A[i-1]`和`D[i] = A[i+1]×…×A[n-1]`两部分的乘积,那么就可以先计算出这个两部分的在做乘积就可以了
- 在接着看下`C[i]`的求解我们可以使用循环暴力求解,那是`O(n**2)`的复杂度,但是可以分析出来`C[i] = C[i-1]*A[i-1]`
- `D[i]`同样可以写出递推式为`D[i] = D[i+1]*A[i+1]`
- 时间复杂度`O(n)`,空间复杂度`O(n)`
- 分析出这个原理,那就撸代码了
### 代码1

```python
class Solution(object):
    def constructArr(self, a):
        """
        :type a: List[int]
        :rtype: List[int]
        """
        length = len(a)
        C = [1] * length
        D = [1] * length
        result = []
        for i in range(1,length):#求C[i]
            C[i] = C[i-1] * a[i-1]
        for i in reversed(range(length-1)):#D[i]
            D[i] = D[i+1] * a[i+1]
        for i in range(length):#求B[i]
            result.append(C[i]*D[i])
        return result
```
- 上面这个代码使用了三次循环,可以对他进行一些简化,就是数组`D`或者数组`C`可以省去一个
- 看代码省去了数组`D`,使用临时变量存储每一个`D[i]`
![image.png](https://pic.leetcode-cn.com/8a5f9c5528d6a0bdaa36ab44f98b5a951bb74cd843b05d5f93b04f4f7d76c28f-image.png)

```
class Solution(object):
    def constructArr(self, a):
        """
        :type a: List[int]
        :rtype: List[int]
        """
        length = len(a)
        result = [1] * length
        temp = 1
        for i in range(1,length):
            result[i] = result[i-1] * a[i-1]
            
        for i in reversed(range(length)):
            result[i] = result[i] * temp
            temp *= a[i]

        return result
        





```
