## [5341. 最后 K 个数的乘积](https://leetcode-cn.com/problems/product-of-the-last-k-numbers/)

## 题意：
实现一个类两个函数，对一个数组具有两个操作：
- 在一个数组末尾添加元素
- 求数组末尾k个元素的乘积

## 思路：
~~在周赛时候，先上来想medium O(n)应该能过吧，果然超时。~~

明显第一个操作已经是O(1)没办法优化，第二个操作如果是求前k个乘积就很明显预处理出前缀和，然后O(1)，同时有了前缀和```pre(i)```也可以O(1)求得**任意区间**的和 ```sum(i,j)```。

```sum(i,j)= pre(j) - pre(i-1)```

那么借用前缀和思想，我们在第一个操作里随便得到前缀积，那后k个乘积很容易想到乘法逆运算除法O(1)可以求得区间的积，自然后k个乘积也很容易。
```mutil(i,j) = pre(j) / pre(i-1)```

但要注意一个细节,插入元素为0的时候，需要特殊处理，如果问的后k个元素里面有0,直接返回0即可。


这样两个操作都是```O(1)```。
## 代码：
```python
class ProductOfNumbers:

    def __init__(self):
        self.data = [1]

    def add(self, num: int) -> None:
        if num == 0:
             self.data = [1]
        else :
            self.data.append(self.data[-1] * num)

    def getProduct(self, k: int) -> int:
        if k>= len(self.data) :
             return 0
        else : 
            return int(self.data[-1] / self.data[-1-k])
```