### 解题思路（方法1）
此处撰写解题思路
对于一个列表中的有序数，找寻确实的数字最容易想到的便是二分法。
当我们二分的值与列表中对应位置的值相等，说明小于该值的部分没有丢失数据；
相反则丢失数据。
时间复杂度O(log n)
空间复杂度O（1）
### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:

        low=0
        high=len(nums)-1
        while low<=high:
            if (low+high)//2==nums[(low+high)//2]:
                low=(low+high)//2+1
            else:high=(low+high)//2-1
        
        return low
```
### 解题思路（方法2）
根据位运算的知识我们知道0与任何数的异或还是其本身，任何数与其自身异或结果为0.
对于长度为n的序列中丢失了一个数，索引就会缺少n本身，所以我们选择n和列表中的元素以及索引求异或。
因为丢失的数是只有一个，其他的数都是成对出现，成对出现的数异或值为0，所以最后剩的就是丢失的数。
时间复杂度O(n)
空间复杂度O(1)
### 代码
class Solution:
    def missingNumber(self, nums: List[int]) -> int:

        temp=len(nums)
        for i in range(len(nums)):
            temp^=i^nums[i]
        return temp

### 结题思路（方法3）
在给定的按顺序连续递增的列表中找寻缺失的数，只需要通过求所有的数的和与有缺失序列的和之差，就能求得
所得的缺失值了。

### 代码
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        return len(nums)*(len(nums)+1)//2-sum(nums)        