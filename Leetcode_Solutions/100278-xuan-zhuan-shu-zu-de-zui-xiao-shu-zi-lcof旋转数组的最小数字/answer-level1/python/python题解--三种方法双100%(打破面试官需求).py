### 直接查找
![image.png](https://pic.leetcode-cn.com/327f842dbf348bf958e2f89f85d3dd6d2f07e5fd0a5d8a55f3b8366b31cd742b-image.png)
- 不多说了,直接查找
- 时间复杂度`O(n)`,空间复杂度`O(1)`
### 代码
```
class Solution(object):
    def minArray(self, numbers):
        """
        :type numbers: List[int]
        :rtype: int
        """
        return min(numbers)

```


### 二分查找(特例分析)
![image.png](https://pic.leetcode-cn.com/be12d58db3cfc974dad127d794a9c574c9de80e02735b1273062254c73f5d34c-image.png)
- 使用二分法解这个题目,先看普通的情况,给定数组`numbers = [3,4,5,1,2]`,通过观察可以看出来最小的数字是`1`,并且这个数组能看做是由两部分组成的,第一部分为前面的递增数组`[3,4,5]`,第二部分为后面的递增数组`[1,2]`,也能看出来前面递增数组中所有的数字大于后面递增数组中的数,而我们所要找的数字`1`是位于后面递增数组的第一位
- 使用二分法,设置头尾两个指针`low`和`high`,`mid = (low + high) / 2`
- 当`numbers[mid] >= numbers[low]`时,说明`mid`此时位于前面的递增数组中,令`mid = low`
- 当`numbers[mid] <= numbers[high]`时,说明`mid`此时位于后面的递增数组中,令`mid = high`
- 可以看出来这样操作,指针`low`永远位于前面的递增数组中,指针`high`位于后面的递增数组中,循环到最后`low`指向前面递增数组的最后一位,指针`high`指向后面数组的第一位,所以终止条件可以设定成`high-low == 1`,此时返回`numbers[high]`即可
- 好了,上面是对一般情况的梳理.下面我们看一些特例
1. 当数组为`[1,2,3,4,5]`时,意思是把数组前0个元素搬到后面,这样的话最小值就是第一个值,所以我们将初始的`mid = low`,指向第一个元素
2. 当数组为`[1,0,1,1,1]`时,我们看下此时`low = 0`,`high=4`,`mid = 2`,并且`numbers[low] == numbers[high] == numbers[mid]`,我们是无法判断`mid`是位于前面还是后面的递增数组的,所以当初先这样的情况需通过顺序查找
- 我么就分分析下`[1,0,1,1,1]`,当不加入上面的条件时,初始`low = 0`,`high=4`,`mid = 2`,`numbers[mid] <= numbers[low]`,此时`mid=2`,此时遍历的数组变为`[1,1,1]`,可以看到其实最小值是`0`,但这个数组中没有包含`0`,所以需要加入上面的条件来判断

- 时间复杂度`O(logn)`,空间复杂度`O(1)`
### 代码

```python
class Solution(object):
    def minArray(self, numbers):
        """
        :type numbers: List[int]
        :rtype: int
        """
        if not numbers:
            return None
        low = 0
        high = len(numbers) - 1
        mid = low
        while numbers[low] >= numbers[high]:
            if high - low == 1:
                mid = high
                return numbers[mid]
            mid = (low + high) / 2
            if numbers[low] == numbers[high] and numbers[mid] == numbers[low]:
                temp = numbers[low]
                for i in numbers[low:high+1]:
                    if temp > i:
                        temp = i
                return temp
            if numbers[mid] >= numbers[low]:#位于前面的递增数组
                low = mid
            elif numbers[mid] <= numbers[high]:#位于后面的递增数组
                high = mid
        return numbers[mid]



```
### 分治法
![image.png](https://pic.leetcode-cn.com/8b973972a25c8ac75f90765d43c901bd519e19539d99b3ad9b115b69e82d29c8-image.png)

- 分治法是不断的缩小范围,从而找到符合条件的解
- 二分法的分析我们知道,数组可以分为前后两个递增数组,下面的分析也都利用递增的特性
- 当`numbers[mid] > numbers[high]`时,说明最小值在`mid`的右边,缩小范围`low = mid + 1`
- 当`numbers[mid] == numbers[high]`时,我们不知道最小值的范围,但是可以肯定的是去除`numbers[high]`是没有影响的,缩小范围`high -= 1`
- 当`numbers[mid] < numbers[high]`时,我们知道最小值的不是`numbers[mid]]`就是在`mid`的左边,缩小范围`high = mid`

### 代码
```
class Solution(object):
    def minArray(self, numbers):
        """
        :type numbers: List[int]
        :rtype: int
        """
        if not numbers:
            return None
        low = 0
        high = len(numbers) - 1
        while low < high:
            mid = (low + high) >> 1
            if numbers[mid] > numbers[high]:
                low = mid + 1
            elif numbers[mid] == numbers[high]:
                high -= 1
            else:
                high = mid
        return numbers[low]

```
