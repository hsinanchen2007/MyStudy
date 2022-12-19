### 解题思路
此题的目的是求一组元素可以组成的所有数字中比这组元素组成的数字下一大的一组序列

- 1.一种特殊情况：当序列的元素递减的时候肯定是不存在比它大的序列了，像[3,2,1]组成的数字321已经是最大的了
- 2.当不是上面的特殊情况的时候，举个例子：
    - [1,3,2,4]的下一大序列是[1,3,4,2]
    - [1,3,4,2]的下一大序列是[1,4,2,3]
    - [1,4,3,2]的下一大序列是[2,1,3,4]
    - 从上面，我们可以发现规律，从序列的后面向前面看，如果nums[i]>nums[i-1]那么这个序列就存在下一大元素
    - a.当序列的最后两个元素满足nums[i]>nums[i-1],那么直接交换位置就可以了，像[1,3,2,4]-->[1,3,4,2]
    - b.当序列是最后两个元素之前的元素满足nums[i]>nums[i-1]，那么我们就要考虑几个问题了，像[1,3,4,2]--》[1,4,2,3]
        - 在[1,3,4,2]中，从后向前遍历，3和4满足条件，交换他们之后还要对i和之后元素进行排序，不然得到的就是[1,4,3,2]
        - 在[1,4,3,2]中，1和4满足条件，但是我们不能直接交换他们，我们要在i之后的序列中找一个满足大于i-1位置元素的最小元素和它交换位置
    

### 代码

```python3
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        flag = 0  # 标记是否存在下一个排列
        for i in range(len(nums)-1, 0, -1):
            # nums[i] > nums[i-1]时，存在下一个排列
            if nums[i] > nums[i-1]:
                flag = 1  
                #取nums得i索引之后的元素，并排序
                s = sorted(nums[i:len(nums)])
                if len(s)>0:
                    #生成满足大于i-1元素的列表，并取最小的，求所在nums中的位置，让这个元素和i-1元素交换位置
                    ss = [j for j in s if j>nums[i-1]][0]
                    c = nums.index(ss,i)
                    
                    nums[i-1],nums[c] = nums[c],nums[i-1]
                    #交换完成后，i-1位置之后的元素都应该是递减的
                    nums[i:] = sorted(nums[i:])
                    
                    return nums
                else:#仅仅是最后两个元素交换位置
                    nums[i - 1], nums[i] = nums[i], nums[i - 1]
                    return nums



        if flag == 0:  # 不存在下一个排列
            nums.sort()

        return nums
        
```