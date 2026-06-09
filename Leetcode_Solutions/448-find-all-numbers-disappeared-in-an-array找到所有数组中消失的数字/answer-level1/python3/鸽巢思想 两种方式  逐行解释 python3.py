# 题解
第一时间想到**一个萝卜一个坑**，鸽巢思想。

## 鸽巢思想
对于题目中$1<=nums[i]<=n$，我们只需将每个数字放到正确的位置上（对应的下标）。再遍历一次数组，那么位置上不是对应的数时，即为缺失的数字

 1. 遍历数组，对于$nums[i]$：
 	+ 循环条件，若$nums[i]!=i+1$并且$nums[i]!=nums[nums[i]-1]$。意思是若当前位置的元素不等于$i+1$，将它放到对应的下标$nums[i]-1$处。为了避免死循环，若正确的位置上已经有了正确的元素，则结束。
 
 2. 遍历排序后的数组，若位置上不是正确的元素，则加入$res$

### 复杂度分析
 - 时间复杂度：$O\left(n\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        res=[]
        for i in range(len(nums)):
            while(nums[i]!=i+1 and nums[i]!=nums[nums[i]-1]):
                nums[nums[i]-1],nums[i]=nums[i],nums[nums[i]-1]
        for i in range(len(nums)):
            if(nums[i]!=i+1):
                res.append(i+1)
        return res

```

## 鸽巢思想的另一种方式
我们将出现过的数字对应的数组下标上的元素值始终变为负数，那么数组中正数的元素的下标可以表示缺失的元素。

### 复杂度分析
 - 时间复杂度：$O\left(n\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        res=[]
        for i in range(len(nums)):
            nums[abs(nums[i])-1]=-abs(nums[abs(nums[i])-1])
        return [i+1 for i in range(len(nums)) if(nums[i]>0)]
```
