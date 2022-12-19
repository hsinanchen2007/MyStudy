### 解题思路
此处撰写解题思路
用了分治法，小白初学算法，代码写的很粗糙，简单的说一下思路
数组中最大的子数组和，如果把数组一分为二，这个和的出现位置无非三种：
1.最大子数组和全部在左边
2.最大子数组和全部在右边
3.最大子数组和跨越中点
可以注意到第一种和第二种方法能够递归实现，第三种方法需要单个列出
由此能够体现分治法把原问题分解为若干个子问题，并且能够递归的求解这些子问题
最后能将子问题合并为一个新的解（在这里第三种情况相当于合并过程），层层递归解出答案

定义了Crossing(nums)函数，用来处理上述的第三种方法，由于是跨越中点最大子数组和
必定包括mid（中点所在位置）点，用了两次循环,第一次遍历的求解从中间到左边开头的最大和
第二次遍历的求解从中间到右边的最大和，最后将两个相加便得到跨越中点最大和

fenzhi(nums)函数便是分治法主函数
基本情况 ：当数组长度小于等于1，说明最多有1个元素，返回该元素
递归情况 ： 每次将数组一分为二，记录每次的左边最大和，右边最大和，跨越中点最大和，并返回其中较大者
不断递归得到答案
### 代码

```python
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def Crossing(nums):
            mid = len(nums) //2
            i = mid-1
            LeftSum =-float("inf")  #此为负无穷
            ThisSum = 0
            RightSum = -float("inf") #此为负无穷
            while(i>=0):
                ThisSum += nums[i]
                if(ThisSum>LeftSum):
                    LeftSum = ThisSum
                i-=1
            i = mid 
            ThisSum = 0
            while(i<len(nums)):
                ThisSum += nums[i]
                if ThisSum >RightSum :
                    RightSum = ThisSum
                i+=1
            return (LeftSum + RightSum)
        
        def fenzhi(nums):
            if len(nums) <= 1:
                return nums[0]
            else :
                mid = len(nums) // 2
                LeftSum = fenzhi(nums[0:mid])
                RightSum = fenzhi(nums[mid:])
                CrossingSum = Crossing(nums)
                if(CrossingSum>=RightSum and CrossingSum >=LeftSum) :
                    return CrossingSum
                elif (LeftSum>=RightSum and LeftSum >=CrossingSum):
                    return LeftSum
                elif (RightSum>=LeftSum and RightSum >=CrossingSum):
                    return RightSum
        return fenzhi(nums)
        















```