### 解题思路
排序是算法基础中的基础，至少有10种以上，除了快排、归并和堆排能实现线性对数阶、希尔实现O(n1.3)复杂度之外，还有3个线性阶复杂度的排序算法：计数、基数和桶排。
当然，这些方法都可以解决这道题。

但今天打算这些方法都不用，来个新花样，那就是借用计数器的性质：会保留初始化时元素的出场顺序。
由于题目限定了目标数值均在-50000到50000之间，那么我们就事先规定好这些数的出场顺序，再用它和目标数组相加，然后把初始化的那些多余数字减掉，返回的就是按预定初始化顺序排序好的数组了。

包括leetcode 791号题，用这个性质会更显骚操作~
[利用Counter实现自定义字符串排序](https://leetcode-cn.com/problems/custom-sort-string/solution/pythoncounterji-shu-qi-sao-cao-zuo-by-luanz/)

talk is cheap, let's see the code!

### 结果
![image.png](https://pic.leetcode-cn.com/06644e58d2620c5f88704d888d262d3a75db360d3d0c0d697b7195223265dbd9-image.png)

好吧，勉强过关！

### 代码

```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        ct = collections.Counter(range(-50000, 50001))
        cn = collections.Counter(nums)
        return (ct+cn-ct).elements()
```
最后，低调推荐个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)
