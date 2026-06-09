对于无需去重的排列来说，每次需要从剩余的数中抽取一个数加入当前排列。因此对于n个数的排列来说有n!种情况。

## 选数法
可以发现每次从剩余的数中抽取一个数加入当前排列这一动作可递归，因此递归函数初版如下：

```
class Solution:
    def permute(self, nums: [int]) -> [[int]]:
        def recursive(permutation, rest_nums, result):
            # 当无剩余数可选时，退出递归
            if len(rest_nums) == 0:
                result.append(permutation.copy())

            for i, num in enumerate(rest_nums):
                permutation.append(num)
                recursive(permutation, rest_nums[:i] + rest_nums[i+1:], result)
                # 去掉此前加入的num，为下一排列做准备
                permutation.pop()

        result = []
        recursive([], nums, result)
        return result

```

初版递归函数中，使用rest_nums[:i] + rest_nums[i+1:]提取下一个待选数组，这样每一次递归都会有额外的空间开销和复制开销用于生成待选数组，能否做进一步优化？

为了优化空间并减少复制的时间开销，可以使用一个数组标记元素是否在待选数组中，但是这时候必须遍历整个原数组来提取待选数组。

```
class Solution:
    def permute(self, nums: [int]) -> [[int]]:
        def recursive(permutation, count, result):
            # 排列计数已满，退出递归
            if count == len(nums):
                result.append(permutation.copy())

            for i, num in enumerate(nums):
                if mark[i] == 0:
                    permutation.append(num)
                    mark[i] = 1
                    recursive(permutation, count + 1, result)
                    permutation.pop()
                    mark[i] = 0
 
        result = []
        mark = [0] * len(nums)  # 0 代表目标元素处于待选数组中, 1 代表已选
        recursive([], 0, result)
        return result
```

## 交换法
选数法通过维护待选数组来生成排列，交换法也是同样。

选数法通过额外的数组来维护，而交换法则是在原数组中维护待选数组，有更好的空间与时间效率。

考虑将原数组分为两个部分，左部分为生成的排列，右部分为待选的数组。
1. 维护生成排列的长度以区分两个部分，当选择i作为排列中的元素时，则swap(nums[count], nums[i])，此时待选数字nums[i]进入排列中，nums[count]作为非排列数进入待选数组中。
2. 递归生成排列，直至count==len(nums)，此时已无待选数字，开始回溯。
3. 再次swap(nums[count], nums[i])，将原数字还原到待选数组中，选取下一个元素进入排列，如此下去便可生成所有排列。

如下图例
![image.png](https://pic.leetcode-cn.com/fc13c380ba4dcdd9b5be491f3dc4e9db5c4ffc7759a8071e019f15bbe0ef51c3-image.png)


```
class Solution:
    def permute(self, nums: [int]) -> [[int]]:
        def recursive(count, result):
            if count == len(nums):
                result.append(nums.copy())

            for i in range(count, len(nums)):
                nums[i], nums[count] = nums[count], nums[i]    
                recursive(count + 1, result)
                nums[i], nums[count] = nums[count], nums[i]
 
        result = []
        recursive(0, result)
        return result
```


