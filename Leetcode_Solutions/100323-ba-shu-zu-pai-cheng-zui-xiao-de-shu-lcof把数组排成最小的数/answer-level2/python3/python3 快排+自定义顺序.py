## 题目
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

 

示例 1:
```
输入: [10,2]
输出: "102"
```

示例 2:
```
输入: [3,30,34,5,9]
输出: "3033459"
```

提示:

0 < nums.length <= 100
说明:

输出结果可能非常大，所以你需要返回一个字符串而不是整数
拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0

>来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



## 思路
通过观察可以发现，如果只有两个数m和n，拼接起来就是'mn'和'nm'，选择较小的就行。

如果数字是三个或者三个以上，那么其中任意两个数的排列方式该是什么样呢？
如果有'mn'<'nm'，那么m一定排在n的前面。

这题的本质实际上是自定义规则对数组进行排序。
为了快一点并且重新练习一下快排算法，于是对快排进行了改造。

## 代码
```
class Solution:
    def minNumber(self, nums: List[int]) -> str:
        nums = [str(num) for num in nums]
        self.quickSort(nums, 0 , len(nums)-1)
        return ''.join(nums)
        

    def quickSort(self,nums, start, end):
        if start >= end: return
        index = self.partition(nums, start,end)
        self.quickSort(nums, start, index-1)
        self.quickSort(nums, index+1, end)

    def partition(self, nums, start, end):
        pivot = nums[end]
        index = start - 1
        for i in range(start,end):
            # 几乎是唯一改变的代码
            if nums[i] + pivot < pivot + nums[i]:
                index += 1
                nums[index],nums[i] = nums[i],nums[index]
        index += 1
        nums[index], nums[end] = nums[end],nums[index]
        return  index
```

## 小结
快排大法好。

两个数字的组合谁在前面在最后的结果中依然在前面。

发现问题的本质是排序。
