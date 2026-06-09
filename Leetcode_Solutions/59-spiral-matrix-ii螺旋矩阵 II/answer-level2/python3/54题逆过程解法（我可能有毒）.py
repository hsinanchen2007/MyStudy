首先上代码
```
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        if n == 1:
            return [[1]]
        elif n == 2:
            return [[1,2],[4,3]]
        s = [[i for i in range(1,n+1)]]
        m = [(n**2-1,n**2)]
        k = 1
        v = 0
        r = n**2-2
        while n-k-1:
            if len(m)>1:
                m = [tuple(range(r-k,r+1))] + list(zip(*m[::-1]))
            else:
                m = [tuple(range(r-k,r+1))] + [m[0][::-1]]
            r = r - k -1
            if v % 2 == 1:
                k += 1
            v += 1
        return s + list(map(list,zip(*m[::-1])))
```
然后上一个54题（螺旋矩阵I）搬运到的一个极为精妙的利用zip方法的解法
```
def spiralOrder(matrix):
    """
    :type matrix: List[List[int]]
    :rtype: List[int]
    """
    a = []
    while matrix:
        a += matrix[0]
        matrix = matrix[1:]
        matrix = list(zip(*matrix))[::-1]
    return a
```
虽然不太懂具体是什么原理，但是在中间加一句`print(matrix)`就可以监测到每一步处理后的matrix，这里给3,4矩阵的过程
![1.png](https://pic.leetcode-cn.com/799de92afa08d4674e467fc5b6c0e859074cb43178bdc56fd76de56b98d5453e-1.png)
![2.png](https://pic.leetcode-cn.com/e7e2d6e9007643dab8fed221bf21c500b477dcecbbdcd4bb77c704339fb2e6c1-2.png)
可以自行尝试观察，除了倒数三行没什么实用，往上看可以发现每一行都是其下一行翻转在zip打包和前面两个/三个有序数组成；
其中的原理也是由于zip可逆，正常的话`*zip()`为`zip()`的逆过程，这里由于都在列表中，所以直接`zip()`即为逆过程，同时[::-1]翻转的过程也是可逆的，
这就注定54题的解题方法可以逆过来还原回矩阵，于是我做出了尝试
首先还是去除倒数三行不看，可以发现往上是第一个元素为两个有序数的执行了两次，三个有序数的执行两次，依次类推数越大前面的第一项有序数逐步增长，并出现两次
这都是由于zip打包的结果，列表中元素越多，往上执行zip第一项的有序数长度越大
由于规律是从列表中两个元组，每个元组中两个元素时出现的所以：
设置`m=[(n**2-1,n**2)]`为初始值
设置`k=1`为初始是有序元组最大值和最小值的差，其实就是长度-1
设置`v=0`记录执行的次数，如果执行是2的倍数次后则`k += 1`增大有序元组的长度，由于v从0记录而且是执行后+1，所以判断条件是`if v % 2 == 1`
设置`r = n**2-2`为最开始有序元组的最大值，最后有序元组为`tuple(range(r-k,r+1)`
然后以上代码就可以将54题过程逆过来最后在加入第一行就可以构造出螺旋矩阵了
![3.png](https://pic.leetcode-cn.com/febf7ae038f6265c42c51c9ce2c3c69d0a25f4b1b3d51af8ee18df52db399736-3.png)




