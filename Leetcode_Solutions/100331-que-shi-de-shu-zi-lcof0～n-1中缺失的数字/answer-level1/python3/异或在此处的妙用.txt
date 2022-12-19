### 解题思路
题目分析： 
该题分情况讨论： 
1.数组长度为0，也就是空的，返回0 
2.数组长度为1，也就是元素是0时，返回1，是1时，返回0 
3.长度大于1： 
3.1缺失的数在数组内 这种情况下发现异或运算在这里是个好东西，从第二个元素遍历开始，对每个元素与其上一个元素加1之后遍历（因为相同元素异或的结果为0），当异或结果不为0时，直接返回当前遍历元素-1。 
3.2缺失的数在数组头部或者尾部 当按照3.1全部遍历完均为0，则说明要找的数在头部或者尾部，判断一下数组第一个元素是否为0即可。 
执行用时 :48 ms, 在所有 Python3 提交中击败了85.56%的用户 
内存消耗 :14.3 MB, 在所有 Python3 提交中击败了100.00%的用户此处撰写解题思路

拓展思考：
当我们要找一个数组中唯一一个出现一次的元素时（其他元素出现次数大于1），这时有些同学会想到用字典计数（from collections import Counter），可行，但是它相比于异或，复杂度高了许多。异或怎么操作呢，如下：

a = [1,2,2,2,1,3,5,4,4,3] 
def search_onlyone(a): 
    b = a[0]
    for i in range(1,len(a)):
        b ^= a[i]
    return b

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            if nums[0] == 1:
                return 0
            else:
                return 1
        else:
            j = 0
            for i in range(1,len(nums)):
                if (nums[i-1]+1)^nums[i] != 0:
                    return nums[i]-1
                    j += 1
            if j == 0 and nums[0] != 0:
                    return nums[0]-1
            elif j == 0 and nums[0] == 0:
                    return nums[-1]+1



```