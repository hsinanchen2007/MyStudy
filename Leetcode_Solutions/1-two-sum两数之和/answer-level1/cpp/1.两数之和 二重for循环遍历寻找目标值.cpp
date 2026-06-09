
一开始就写好了，总是运行错误，原来是我给形参赋了值（注解就是出错的地方），这跟C++不一样，C++中形参的值不影响实参，Python中函数给形参赋值会影响到实参…………所以取消了赋值后就成功了。

```python
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        #nums=[2,7,11,15]
        n=len(nums)
        #target=9
        for i in range(n):
            for j in range(i+1,n):
                if nums[i]+nums[j]==target:
                    return i,j
                    break
                else:
                    continue

```