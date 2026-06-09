两个指针分别设为1与n时，取左中位数或右中位数时均可：
```
class Solution(object):
    def mySqrt(self, x):
        if x <= 1:
            return x
        i, j = 1, x
        while i < j: 
            mid = (i + j) / 2   # 取左中位数
            if mid*mid == x:
                return mid
            elif mid*mid < x: 
                i = mid  + 1    # 加一
            else:
                j = mid
        return i - 1
```
或
```
class Solution(object):
    def mySqrt(self, x):
        if x <= 1:
            return x
        i, j = 1, x
        while i < j: 
            mid = (i + j + 1) / 2   # 取右中位数
            if mid*mid == x:
                return mid
            elif mid*mid < x: 
                i = mid
            else:
                j = mid - 1         # 减一
        return i
```
都可以正确运行

但是 当两个指针分别设为1与n/2时，上述取右中位数的代码依然可以正确运行，而取左中位数的代码会出现错误，例如输入4输出1。

原因是
取左中位数的代码 【在两个指针分别设为1与n/2时 输入4和5】 的指针变化 都是如下最左边的过程 可以看到结果是错误的

![image.png](https://pic.leetcode-cn.com/57db130b23832f77cac37a5b1678bf9b335e283e664e13a96f7fcecfeb5f30bc-image.png)

而取右中位数的代码 当两个指针分别设为1与n/2时，对于输入4和5 的指针变化 都是如下最左边的过程 可以看到结果是正确的

![image.png](https://pic.leetcode-cn.com/4e12f0ae6a71a91a01eab43f51f08006b753793f282888a4a7cad56365ab9940-image.png)

原因是因为 在指针分别设为1与n/2时 这里有一个取左侧操作。

如果我们把指针分别设为1与（n+1）/2，取左中位数的代码 输入4和5 的指针变化 如下的过程 可以看到结果是错误的

![image.png](https://pic.leetcode-cn.com/97852a3ac0651b5feff65a0cea8ada736b9f6e2f0b94c09f48a579b218a800b0-image.png)

如果我们把指针分别设为1与（n/2）+1，取左中位数的代码 输入4和5 的指针变化 如下的过程 可以看到结果是错误的

![image.png](https://pic.leetcode-cn.com/a39aa9a20b87135cef80af142865b7cc31f80d4b90741017232ae3b67336ff54-image.png)
