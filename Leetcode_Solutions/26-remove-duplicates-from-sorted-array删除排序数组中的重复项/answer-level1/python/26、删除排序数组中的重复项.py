### 解题思路
注意：数组是有序的，且测试用例中有数组含有负数，还有不能额外开辟空间，所以不能使用集合set

方法一：额外开辟了一个数组空间（其实是不可取的），一边遍历一边往新数组添加数值，遍历下一个数的时候判断该数值是否存在于新数组中，是就在nums中删除该数值
执行用时 :1080 ms
内存消耗 :14.6 MB

方法二：使用x和y分别指向前一个数值和下一个数值，x和y指向的数值不同
执行用时 :36 ms
内存消耗 :13.6 MB
![1.jpg](https://pic.leetcode-cn.com/a43c2f1be826d9ef1c3ec7fc4f5a3f4f68e520970fba85a0178dae53db79b555-1.jpg)


### 代码

```python
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #方法一：
        '''
        a = []
        x = 0
        for i in range(len(nums)):
            if nums[x] not in a:
                a.append(nums[x])
                x = x+1
            else:
                del nums[x]
        del a
        return len(nums)
        '''

        #方法二：
        if nums==[]:             #测试用例中含有[]空数组，直接返回即可
            return len(nums)

        #若数组不为空
        x=0
        y=0
        for i in nums[1:]:       
            y=y+1
            if(nums[x]!=i):      #寻找不等于nums[x]的数值的下标
                del nums[x+1:y]  #删除nums[x]到nums[y]之间的数（注意：nums[x]!=nums[y]）
                x=x+1
                y=x
        del nums[x+1:]           #处理数组最后的数值是重复的情况
        return len(nums)