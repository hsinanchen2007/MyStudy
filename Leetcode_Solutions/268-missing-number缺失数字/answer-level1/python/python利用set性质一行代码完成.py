python中set支持set的并、交、补、差等操作，此题利用{range(len(nums)+1)}和nums只差一个元素其他都相等的性质，可以通过二者的difference()或直接相减得到结果。注意，差得到的结果是一个集合{a}，而输出的结果应当是一个数a。
代码如下：
```
def missingNumber(self, nums: List[int]) -> int:
        return (set(range(len(nums)+1)) - set(nums)).pop()
```
![image.png](https://pic.leetcode-cn.com/4f278edd10caade710d35fb0a921611fd8770a5206f991c725c2a5be133d3d85-image.png)
