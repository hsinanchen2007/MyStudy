### 双指针(在原数组上修改)
- 设置两个指针`start = 0`,`end = len(nums) - 1`分别指向数组的头和尾
1. 如果头尾对应的数分别为奇偶,那么`start`右移一位,`end`左移一位
2. 如果头尾对应的数分别为偶奇,那么交换两个指针所对应的元素
3. 如果头尾对应的数分别为奇奇,那么`start`右移一位
4. 如果头尾对应的数分别为偶偶,那么`end`左移一位
- 时间复杂度`O(n)`,空间复杂度`O(1)`
- 下面谢了两套代码,原理是一样的
### 代码1
![image.png](https://pic.leetcode-cn.com/1cd998d5412536917e413c68c0360b81cceb78aa0c2ab3e7197739ca5211e5b6-image.png)
```python
class Solution(object):
    def exchange(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        low = 0
        high = len(nums) - 1
        while low < high:
            if (nums[high] & 1) and (nums[low] & 1 == 0) : # 偶奇
                nums[high], nums[low] = nums[low], nums[high]
                low += 1
                high -= 1
            elif nums[low] & 1 == 0 and nums[high] & 1 == 0: # 偶偶
                high -= 1
            elif nums[low] & 1 and nums[high] & 1: #奇奇
                low += 1
            else:#奇偶
                low += 1
                high -= 1
        return nums

```
### 代码2
![image.png](https://pic.leetcode-cn.com/912dc3aed9a4c6da5ca1c9296903914e48ba14a027cef5c1a1658192baf08ff0-image.png)

```
class Solution(object):
    def exchange(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        low = 0
        high = len(nums) - 1
        while low < high:
            while low < high and nums[low] & 1:
                low += 1
            while low < high and nums[high] & 1 == 0:
                high -= 1
            if low < high:
                nums[low], nums[high] = nums[high], nums[low]
        return nums



```
- 摘自剑指offer
- 如果我们将题目改一下,要求将是3的倍数的数字放到前面,不是3的倍数的数字放到后面;或者是要求将负数放在前面将正数放在后面
- 思考下这中类似的问题,应该怎么处理呢?
- 应该不能看出只需要改变下判断条件即可,我们是不是能把下面***加粗的判断条件换成相应的函数***,这样做的目的增加了我们函数的可扩展性,在这种模式下很方便地把已有的解决方案扩展到同类的问题上

while low < high:
    while low < high and **nums[low] & 1**:
        low += 1
    while low < high and **nums[high] & 1 == 0**:
        high -= 1
    if low < high:
        nums[low], nums[high] = nums[high], nums[low]
    return nums
