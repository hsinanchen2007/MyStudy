# 题解
和[1.两数之和 leetcode](https://leetcode-cn.com/problems/two-sum/solution/) [1.两数之和 CSDN](https://blog.csdn.net/zhushaojiecumt/article/details/102846196)不同之处在于，本题附加了有序的特殊限定。同样可以借助于暴力法在时间复杂度$O\left(n^{2}\right)$和空间$O(1)$解决。和哈希表时间$O\left(n\right)$和空间$O\left(n\right)$完成。
本题，我们利用排序数组的性质，采用双指针来在时间$O\left(n\right)$和空间$O\left(1\right)$解决。


## 双指针

 1. 特判，若数组为空，返回$[]$
 2. 定义左指针$l=0$指向最小元素，定义右指针$r=n-1$指向最大元素
 3. 循环条件$l<r$：
 	+ 若$numbers[l]+numbers[r]==target$，则返回$[l+1,r+1]$
 	+ 若$numbers[l]+numbers[r]>target$，说明右边的值太大，调小一点，即$r=r-1$
 	+ 否则说明左边的值太小，令$l=l+1$
 
 4. 执行到这步，若不返回说明无解，返回$[-1,-1]$
### 复杂度分析

 - 时间复杂度：$O\left(n\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        if(not numbers):
            return []
        res=[]
        n=len(numbers)
        l=0
        r=n-1
        while(l<r):
            if(numbers[l]+numbers[r]==target):
                return [l+1,r+1]
            elif(numbers[l]+numbers[r]>target):
                r=r-1
            else:
                l=l+1
        return [-1,-1]
```

## 暴力法
两次循环
第一次循环，对于数组中每一个数 **nums[i]** 进行遍历
第二次循环，从当前数的下一个数 **nums[j]** ,其中 **j>i** 继续遍历，判断**nums[i]+num[j]** 是否等于**target**.
### 复杂度分析

 - 时间复杂度：$O\left(n^{2}\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n=len(nums)
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if(nums[i]+nums[j]==target):
                    return [i,j]
        return False
```



## 两次哈希表

 - step1 将数组中所有元素存入词典（哈希表），键为**nums[i]**，值为索引**i**.
 - step2 遍历数组，判断**target-nums[j]**  是否在词典中，且对应的索引不为其本身，即**dict[target-nums[j]]** 不等于**j**. 若满足条件，则返回.
### 复杂度分析

 - 时间复杂度：$O\left(n\right)$
 - 空间复杂度：$O\left(n\right)$

### Python

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict={}
        for i in range(len(nums)):
            dict[nums[i]]=i
        for j in range(len(nums)):
            tmp=target-nums[j]
            if(tmp in dict and dict[tmp]!=j):
                return [j,dict[tmp]]
        return False
```

## 一次哈希表
我们在遍历时，将**target-nums[i]** 存入词典，值为索引**i**.这样在遍历时，只要判断后续元素是否存在于词典中，即可满足条件.如：[2,7,11,15] target=9，将9-2=7 存入词典，第二个元素7在词典中存在，则返回.

### 复杂度分析

 - 时间复杂度：$O\left(n\right)$
 - 空间复杂度：$O\left(n\right)$

### Python

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict={}
        for i in range(len(nums)):
            if(nums[i] in dict):
                return [i,dict[nums[i]]]
            else:
                dict[target-nums[i]]=i
        return False
```
