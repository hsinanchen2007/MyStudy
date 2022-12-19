## 1、暴力求解

- 思路
去循环数组，发现元素等于0，在数组末尾添加元素0，并且删除 这个元素（第一个为0的元素（remove实现））
- 代码
``` 
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in nums:
            if i == 0:
                nums.append(0) 
                nums.remove(0)    
```
- 结果
    - 21 / 21 个通过测试用例
    - 状态：通过
    - 执行用时：252 ms
- 特点
    - 代码简洁
    - 时间复杂度相对较高（对数组增加和删除）
- 思考
理论上：如果先去掉0的话，在添加元素时就不需要开辟新的内存空间，应该更高效
实际上：将nums.remove(0) 移动到上面，执行用时多了30ms

## 2、类比冒泡
- 思路
类比冒泡排序，循环数组，遇到非0元素时将非0元素与第一号元素(sums[0])调换位置，从而实现
- 代码
```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        j = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[i], nums[j] = nums[j],nums[i]
                j += 1
```
- 结果
    - 21 / 21 个通过测试用例
    - 状态：通过
    - 执行用时：88 ms
- 特点
    - 类比冒泡也是一个好的想法
    - Python调换位置不需要引入中间变量独到优势
    - 代码效率好很多

 

