
解题思路：回溯的思想。题目特性：生成一个排列需要对`len(nums)`个位置填放不同元素
![1.png](https://pic.leetcode-cn.com/2f1db1a0cbcbc6df1ba36661ee32bafa478f59b125aa7f9e6097fee3e98de2c0-1.png)

1、判断是否满足一个排列的条件：`当前排列数量 == 数组长度`。
	若满足，则将排列加入到返回列表里，然后返回，执行5；否则，进行2
2、因为题目的特性，需要对`len(nums)`个位置填放不同元素，因此需要递归`len(nums)`层。
对于第`index`层，需要在第`index`个位置尝试放所有的元素。因此，在`for`循环中，每次都把第i个位置与`index`交换，就可以实现在第`index`个位置中填放所有元素的效果。
3、通过一个`tmp`列表来保存当前的排列，在每一层递归中，都在tmp的末尾添加该层的元素
4、递归：传入的`index+1`，代表进入了下一层。
5、回溯：当`tmp`构成一个可行排列后，就在它的末尾弹出一个元素。同时，由于这一步是在递归返回后执行，因此表示这一层的第`index`位置的元素所有可能的排列都已经遍历完毕，故需要把这一层在一开始的那次交换元素的操作给置换回来。

时间复杂度：
1、一共需要`n=len(nums)`层递归
2、第`i`层递归需要遍历`n-i`次【`i`从0开始】
因此，需要O（n！）



```
class Solution:
    def permute(self, nums):
        # 边界条件判断
        if not nums:
            return 0
        res = []
        self.backtracking(nums, 0, [], res)

        return res

    def backtracking(self, nums, index, tmp, res):
        # 判断满足一个排列的目标
        if len(tmp) == len(nums):
            res.append(tmp.copy())  # 保存结果
            return

        # 遍历所有情况
        for i in range(index, len(nums)):
            # i与index进行交换
            # 然后将交换后的元素插入当前排列中
            nums[i], nums[index] = nums[index], nums[i]
            tmp.append(nums[index])  

            # 递归：缩小1个规模
            self.backtracking(nums, index+1, tmp, res)
            # 回溯：
            # 1、将之前交换的元素再换回来
            # 2、将当前排列弹出1个值
            nums[i], nums[index] = nums[index], nums[i]
            tmp.pop()
```