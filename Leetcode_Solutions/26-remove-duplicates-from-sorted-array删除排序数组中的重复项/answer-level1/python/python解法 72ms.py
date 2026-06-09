#### 解题思路

##### 利用set函数去重

拿到题之后，很容易会想到，用`set()`去除数组中的重复值，然后返回`nums`的长度即可，但是要注意到的是`set()`函数处理时，并不是在原列表上进行的，处理的结果需要重新开辟地址空间才能保存，所以只要是使用了`set()`函数的已经不符合题目中的原地修改了。

##### 遍历数组求解

再浏览一次题目，能够联想到我们之前在做`三数之和`，经常需要通过判断前后两个字段是否相同去除前后数字相同而产生的可能的重复解，这里很自然的，就是说，如果前后两个数字相同，那么我们删除前一个字符。于是就有如下**错误代码**:

```python
class Solution(object):
    def removeDuplicates(self, nums):
            for i in range(1,len(nums)):
            if nums[i] == nums[i-1]:
                $nums.remove(nums[i-1])
                print(len(nums))
                continue
        return len(nums)
```

上述代码的问题在于，在`remove()`遍历得到的重复值时，整个列表的长度已经改变了，而在`for`循环中，索引值没有进行对应的修改，而导致了在遍历过程中，非常容易导致相邻发重复值因为索引值的原因而导致的遗漏。解决方式如下：

```python
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left,right = 1,len(nums)
        while left < right:
            if nums[left] == nums[left-1]:
                nums.remove(nums[left-1])
                right = right -1
                left = left -1
            left = left + 1
        return len(nums)
```

上述代码，能够通过所有测试样例，但是，从执行结果上看，无论是时间开销还是空间开销都谈不上高效。

>执行用时 :528 ms, 在所有 python 提交中击败了11.91%的用户
>
>内存消耗 :13.6 MB, 在所有 python 提交中击败了17.42%的用户

##### 复杂度分析

上述解法的复杂度分析如下：

> 时间复杂度：O(N)，代码只涉及到遍历列表长度
>
> 空间复杂度 ：O(1)，代码中仅使用两个变量保存指针

#### 如何调优

上述代码中，我们对于重复的数字的处理方式是使用内置函数`remove()`删除重复值中的前一个，实际上，这带来额外的开销。题目中，最后的要求是返回删除这些重复数字后列表的长度，，我们**大可以在遍历过程中，对于发现的重复数字，进行移动，而非删除**，简单整理思路，我们可以**对相邻元素不相等的情况计数**，用`tmp`表示，每次不相等情况下的后面的数，存放到由`tmp`标识的地址中【tmp计数可以从1计数】，有如下代码，【while循环换成了for，因为在上面的解答中，是判断相同，而这里判断不同时，写代码的过程中，发现可以由for循环更好的表达】

```python
class Solution(object):
    def removeDuplicates(self, nums):
    tmp = 1
        for left in range(1,len(nums)):
            if  nums[left] != nums[left-1]:
                nums[tmp] = nums[left]
                tmp = tmp + 1
        return nums[:tmp]
```

再来看现在的执行时间，如下，尽管在空间开销并没有改变，但是执行的时间由**528ms**减少到了**72ms**.要注意的是，两种代码形式**时空复杂度没有变化**。

>执行用时 :72 ms, 在所有 python 提交中击败了88.30%的用户
>
>内存消耗 :13.6 MB, 在所有 python 提交中击败了22.67%的用户